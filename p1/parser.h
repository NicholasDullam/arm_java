#ifndef parser_h
#define parser_h

#include <stdio.h>

// enumerate all tokens (terminals) here
enum Token {
    TOK_AND,                                                                    // operators
    TOK_OR,
    TOK_LESS,
    TOK_GREAT,
    TOK_LEQ,
    TOK_GREQ,
    TOK_NEQ,
    TOK_EQ,
    TOK_PLUS,
    TOK_MINUS,
    TOK_MULT,
    TOK_DIV,

    KW_CLASS,                                                                   // keywords
    KW_MAIN,
    KW_PUBLIC,
    KW_STATIC,
    KW_VOID,
    KW_NEW,
    KW_TRUE,
    KW_FALSE,
    KW_INT,
    KW_BOOLEAN,
    KW_STRING,
    KW_IF,
    KW_ELSE,
    KW_RETURN,
    KW_WHILE,
    KW_SYSPLN,
    KW_SYSP,

    TOK_ID,                                                                     // identifiers

    LIT_INT,                                                                    // literals
    LIT_STRING,

    TOK_DOT,                                                                    // other terminals
    TOK_SEMICOLON,
    TOK_OPENBRACE,
    TOK_CLOSEBRACE,
    TOK_OPENPAR,
    TOK_CLOSEPAR,
    TOK_OPENBRACK,
    TOK_CLOSEBRACK,
    TOK_ASSIGN,

    TOK_EOF
};

void syntax_error();
void set_instream(FILE*);

void MainClass();
void Program();
void VarDecl();
void PrimeType();
void TypeTail();
void Type();
void StatementList();
void Statement();
void Exp();
void IndexTail();
void Index();
void LeftValueTail();
void LeftValue();

#endif