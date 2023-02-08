#include <stddef.h>                                                             /* for NULL */
#include <stdlib.h>                                                             /* for EXIT_SUCCESS and EXIT_FAILURE */
#include <stdbool.h>                                                            /* for bool, true and false */
#include "parser.h"

// yylex is used to get tokens from lex
extern int yylex();
int current_token;

// advance current token
static void consume() {
    current_token = yylex();
}

// return true if current token is expected
// otherwise return false
static bool peek(int expected_token) {
    if (current_token == expected_token) return true;
    return false;
}

// print error and exit program
static void error() {
    fprintf(stderr, "syntax error, abort\n");
    exit(1);
}

// peek the expected token, error if mistake and consume otherwise
static void match(int expected_token) {
    if (!peek(expected_token)) error();
    else consume();
}

/*
    Program -> MainClass
    FIRST(Program) = FIRST(MainClass) = { class }
    FOLLOW(PROGRAM) = { $ }
*/
void Program() {
    MainClass();
}

/*
    MainClass -> class id { public static void main ( String [] id ) { StatementList }}
    FIRST(MainClass) = { $ }
*/
void MainClass() {
    match(KW_CLASS);
    match(TOK_ID);
    match(TOK_OPENBRACE);
    match(KW_PUBLIC);
    match(KW_STATIC);
    match(KW_VOID);
    match(KW_MAIN);
    match(TOK_OPENPAR);
    match(KW_STRING);
    match(TOK_OPENBRACK);
    match(TOK_CLOSEBRACK);
    match(TOK_ID);
    match(TOK_CLOSEPAR);
    match(TOK_OPENBRACE);
    StatementList();
    match(TOK_CLOSEBRACE);
    match(TOK_CLOSEBRACE);
}

/*
    StatementList -> Statement StatementList
                  -> epsilon
    FIRST(StatementList) = FIRST(Statement) = { int, boolean, String, "{", if, while, System.out.println,
                                                System.out.print, id, return }
    FOLLOW(StatementList) = { "}" } 
*/
void StatementList() {
    if (peek(KW_INT) || peek(KW_BOOLEAN) || peek(KW_STRING) || peek(TOK_OPENBRACE) ||
        peek(KW_IF) || peek(KW_WHILE) || peek(KW_SYSPLN) || peek(KW_SYSP) || peek(TOK_ID) || peek(KW_RETURN)) {
        Statement();
        StatementList();
    } else if (peek(TOK_EOF)) {
        return;
    } else error();
}

/*
    Statement -> VarDecl
              -> { StatementList }
              -> if ( Exp ) Statement else Statement
              -> while ( Exp ) Statement
              -> System.out.println ( Exp ) ;
              -> System.out.print ( Exp ) ;
              -> LeftValue = Exp ;
              -> return Exp ;
    FIRST(Statement) = FIRST(VarDecl) union { "{" } union { if } union { while } union
                       { System.out.println } union { System.out.print } union FIRST(LeftValue)
                       union { return } = { int, boolean, String, "{", if, while, System.out.println,
                       System.out.print, id, return }
    FOLLOW(Statement) = 
*/
void Statement() {

}

/*
    Exp -> ( Exp ) ExpTail
        -> LeftValue ExpLength ExpTail
        -> INTEGER_LITERAL ExpTail
        -> STRING_LITERAL ExpTail
        -> true ExpTail
        -> false ExpTail
        -> new PrimeType Index ExpTail
*/
void Exp() {
    if (peek(LIT_INT) || peek(LIT_STRING) || peek(KW_TRUE) || peek(KW_FALSE)) consume();
    else if (peek(KW_NEW)) {
        match(KW_NEW);
        PrimeType();
        Index();
    } else if (peek(TOK_OPENPAR)) {
        match(TOK_OPENPAR);
        Exp();
        match(TOK_CLOSEPAR);
    } else error();
}

/*
    ExpTail -> Operator Exp ExpTail
            -> epsilon
    FIRST(ExpTail) = FIRST(Operator) = { &&, ||, <, >, <=, >=, !=, ==, +, -, *, / }
*/
void ExpTail() {

}

/*
    ExpDecl -> = Exp
            -> epsilon
    FIRST(ExpDecl) = { = }
*/
void ExpDecl() {

}

/*
    ExpList -> , id ExpDec ExpList
            -> epsilon
    FIRST(ExpList) = { , }
*/
void ExpList() {

}

/*
    ExpLength -> . length
              -> epsilon
    FIRST(ExpLength) = { . }
*/
void ExpLength() {

}

/*
    VarDecl -> Type id ExpDecl ExpList ;
    FIRST(VarDecl) = FIRST(TYPE) = { int, boolean, String }
*/
void VarDecl() {
    Type();
    match(TOK_ID);
    ExpDecl();
    ExpList();
}

/*
    PrimeType -> int
              -> boolean
              -> String
    FIRST(PrimeType) = { int, boolean, String }
*/
void PrimeType() {
    if (peek(KW_INT) || peek(KW_BOOLEAN) || peek(KW_STRING)) consume();
    else error();
}

/*
    TypeTail -> PrimeType TypeTail
             -> [ ]
             -> epsilon
    FIRST(TypeTail) = FIRST(PrimeType) union { [ } = { int, boolean, String, [ }
*/
void TypeTail() {
    if (peek(KW_INT) || peek(KW_BOOLEAN) || peek(KW_STRING)) {
        PrimeType();
        TypeTail();
    } else if (peek(TOK_OPENBRACK)) {
        match(TOK_OPENBRACK);
        match(TOK_CLOSEBRACK);
    } else if (peek(TOK_CLOSEBRACK)) {
        consume();
    } else if (peek(TOK_EOF)) {
        return;
    } else error();
}

/*
    Type -> PrimeType TypeTail
    FIRST(Type) = FIRST(PrimeType) = { int, boolean, String }
*/
void Type() {
    PrimeType();
    TypeTail();
}

/* 
    IndexTail -> [ Exp ] IndexTail
              -> epsilon
    FIRST(IndexTail) = { [ }
*/
void IndexTail() {
    if (peek(TOK_OPENBRACK)) { // rule 1
        match(TOK_OPENBRACK);
        Exp();
        match(TOK_CLOSEBRACK);
        IndexTail();
    } else if (peek(TOK_CLOSEBRACK)) { // rule 2
        consume();
    } else if (peek(TOK_EOF)) { // rule 2
        return;
    } else error();
}

/* 
    Index -> [ Exp ] IndexTail
    FIRST(Index) = { [ }
*/
void Index() {
    match(TOK_OPENBRACK);
    Exp();
    match(TOK_CLOSEBRACK);
    IndexTail();
}

/*
    LeftValueTail -> [ Exp ] LeftValueTail
                  -> epsilon
    FIRST(LeftValueTail) = { [ }
*/
void LeftValueTail() {

}

/*
    LeftValue -> id LeftValueTail
    FIRST(LeftValue) = { id }
*/
void LeftValue() {
    match(TOK_ID);
    LeftValueTail();
}

/*
    Operator -> &&
             -> ||
             -> <
             -> >
             -> <=
             -> >=
             -> !=
             -> ==
             -> +
             -> -
             -> *
             -> /
    FIRST(Operator) = { &&, ||, <, >, <=, >=, !=, ==, +, -, *, / }
*/
void Operator() {
    if (peek(TOK_AND) || peek(TOK_OR) || peek(TOK_LESS) || peek(TOK_GREAT) || 
        peek(TOK_LEQ) || peek(TOK_GREQ) || peek(TOK_NEQ) || peek(TOK_EQ) || 
        peek(TOK_PLUS) || peek(TOK_MINUS) || peek(TOK_MULT) || peek(TOK_DIV)) consume();
    else error();
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char *path = argv[1];
        FILE *file = fopen(path, "r");
        if(file == NULL) {
            perror("Cannot open file");
            return EXIT_FAILURE;
        }

        set_instream(file);
    }

    // call the function to match the start non terminal here
    consume();
    Program();

    if (current_token != TOK_EOF) error();
    return EXIT_SUCCESS;
}