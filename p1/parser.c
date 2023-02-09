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
    } // rule 1
    else if (peek(TOK_CLOSEBRACE)) return; // rule 2
    else error();
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
    FOLLOW(Statement) = { int, boolean, String, "{", if, while, System.out.println,
                                                System.out.print, id, return, "}" }
*/
void Statement() {
    if (peek(KW_RETURN)) {
        match(KW_RETURN);
        Exp();
        match(TOK_SEMICOLON);
    } // rule 8
    else if (peek(KW_SYSPLN)) {
        match(KW_SYSPLN);
        match(TOK_OPENPAR);
        Exp();
        match(TOK_CLOSEPAR);
        match(TOK_SEMICOLON);
    } // rule 5
    else if (peek(KW_SYSP)) {
        match(KW_SYSP);
        match(TOK_OPENPAR);
        Exp();
        match(TOK_CLOSEPAR);
        match(TOK_SEMICOLON);
    } // rule 6
    else if (peek(KW_WHILE)) {
        match(KW_WHILE);
        match(TOK_OPENPAR);
        Exp();
        match(TOK_CLOSEPAR);
        Statement();
    } // rule 4
    else if (peek(KW_IF)) {
        match(KW_IF);
        match(TOK_OPENPAR);
        Exp();
        match(TOK_CLOSEPAR);
        Statement();
        match(KW_ELSE);
        Statement();
    } // rule 3
    else if (peek(TOK_OPENBRACE)) {
        match(TOK_OPENBRACE);
        StatementList();
        match(TOK_CLOSEBRACE);
    } // rule 2
    else if (peek(KW_INT) || peek(KW_BOOLEAN) || peek(KW_STRING)) {
        VarDecl();
    } // rule 1
    else if (peek(TOK_ID)) {
        LeftValue();
        match(TOK_ASSIGN);
        Exp();
        match(TOK_SEMICOLON);
    } else error();
}

/*
    Exp -> ExpPrefix ExpTail
*/
void Exp() {
    ExpPrefix();
    ExpTail();
}

/*
    ExpPrefix -> ( Exp )
            -> LeftValue ExpLength
            -> INTEGER_LITERAL
            -> STRING_LITERAL
            -> true ExpTail
            -> false ExpTail
            -> new PrimeType Index
    FIRST()
*/
void ExpPrefix() {
    if (peek(LIT_INT) || peek(LIT_STRING) || peek(KW_TRUE) || peek(KW_FALSE)) consume(); // rules 3, 4, 5, 6
    else if (peek(KW_NEW)) {
        match(KW_NEW);
        PrimeType();
        Index();
    } // rule 7
    else if (peek(TOK_OPENPAR)) {
        match(TOK_OPENPAR);
        Exp();
        match(TOK_CLOSEPAR);
    } // rule 1
    else if (peek(TOK_ID)) {
        LeftValue();
        ExpLength();
    } // rule 2
    else error();
}

/*
    ExpTail -> Operator ExpPrefix ExpTail
            -> epsilon
    FIRST(ExpTail) = FIRST(Operator) = { &&, ||, <, >, <=, >=, !=, ==, +, -, *, / }
    FOLLOW(ExpTail) = { ) }
*/
void ExpTail() {
    if (peek(TOK_AND) || peek(TOK_OR) || peek(TOK_LESS) || peek(TOK_GREAT) || 
    peek(TOK_LEQ) || peek(TOK_GREQ) || peek(TOK_NEQ) || peek(TOK_EQ) || 
    peek(TOK_PLUS) || peek(TOK_MINUS) || peek(TOK_MULT) || peek(TOK_DIV)) {
        Operator();
        ExpPrefix();
        ExpTail();
    } // rule 1
    else if (TOK_CLOSEPAR) return; // rule 2
    else error();
}

/*
    ExpDecl -> = Exp
            -> epsilon
    FIRST(ExpDecl) = { = }
    FOLLOW(ExpDecl) = { FIRST(ExpList), FOLLOW(ExpList) } = { ",", ; }
*/
void ExpDecl() {
    if (peek(TOK_ASSIGN)) {
        match(TOK_ASSIGN);
        Exp();
    } // rule 1
    else if (peek(TOK_COMMA) || peek(TOK_SEMICOLON)) return; // rule 2
    else error();
}

/*
    ExpList -> , id ExpDecl ExpList
            -> epsilon
    FIRST(ExpList) = { , }
    FOLLOW(ExpList) = { ; } 
*/
void ExpList() {
    if (peek(TOK_COMMA)) {
        match(TOK_COMMA);
        match(TOK_ID);
        ExpDecl();
        ExpList();
    } // rule 1
    else if (peek(TOK_SEMICOLON)) return; // rule 2
    else error();
}

/*
    ExpLength -> . length
              -> epsilon
    FIRST(ExpLength) = { . }
    FOLLOW(ExpList) = { FOLLOW(ExpPrefix) } = { ), &&, ||, <, >, <=, >=, !=, ==, +, -, *, / }
*/
void ExpLength() {
    if (peek(TOK_DOT)) {
        match(TOK_DOT);
        match(KW_LENGTH);
    } // rule 1
    else if (peek(TOK_AND) || peek(TOK_OR) || peek(TOK_LESS) || peek(TOK_GREAT) || 
        peek(TOK_LEQ) || peek(TOK_GREQ) || peek(TOK_NEQ) || peek(TOK_EQ) || 
        peek(TOK_PLUS) || peek(TOK_MINUS) || peek(TOK_MULT) || peek(TOK_DIV) || peek(TOK_CLOSEPAR)) return; // rule 2
    else error();
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
    match(TOK_SEMICOLON);
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
    TypeTail -> [ ] TypeTail
             -> epsilon
    FIRST(TypeTail) = FIRST(PrimeType) union { [ } = { int, boolean, String, [ }
    FOLLOW(TypeTail) = { FOLLOW(Type) } = { id }
*/
void TypeTail() {
    if (peek(TOK_OPENBRACK)) {
        match(TOK_OPENBRACK);
        match(TOK_CLOSEBRACK);
        TypeTail();
    } // rule 1
    else if (peek(TOK_ID)) return; // rule 2
    else error();
}

/*
    Type -> PrimeType TypeTail
    FIRST(Type) = FIRST(PrimeType) = { int, boolean, String }
    FOLLOW(Type) = { id }
*/
void Type() {
    PrimeType();
    TypeTail();
}

/* 
    IndexTail -> [ Exp ] IndexTail
              -> epsilon
    FIRST(IndexTail) = { [ }
    FOLLOW(IndexTail) = { FOLLOW(Index) } = { ), &&, ||, <, >, <=, >=, !=, ==, +, -, *, / }
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
    FIRST(LeftValueTail) = { [ }\
    FOLLOW(LeftValueTail) = { FOLLOW(LeftValue) } = { =, . }
*/
void LeftValueTail() {
    if (peek(TOK_OPENBRACK)) {
        match(TOK_OPENBRACK);
        Exp();
        match(TOK_CLOSEBRACK);
        LeftValueTail();
    }
    else if (peek(TOK_ASSIGN) || peek(TOK_DOT) || peek(TOK_AND) || peek(TOK_OR) || peek(TOK_LESS) || 
        peek(TOK_GREAT) || peek(TOK_LEQ) || peek(TOK_GREQ) || peek(TOK_NEQ) || peek(TOK_EQ) || 
        peek(TOK_PLUS) || peek(TOK_MINUS) || peek(TOK_MULT) || peek(TOK_DIV) || peek(TOK_CLOSEPAR)) return;
    else error();
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