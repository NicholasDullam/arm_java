%option noyywrap
%option yylineno

%{
#include <stdio.h>                                                              /* for fprintf() */
#include <stdlib.h>                                                             /* for EXIT_FAILURE */

#include "parser.h"

void syntax_error() {
    fprintf(stderr, "Syntax errors in %d\n", yylineno);
    exit(EXIT_FAILURE);
}
%}

%%

[ \t\r\n]*                           { }                                                 /* whitespace */

"//".*                               { }                                                 /* inline comments */
"/*"([^\*]|("*"+[^\/\*]))*"*"+"/"    { }                                                 /* block comments */

"&&"                                 { return TOK_AND; }                                 /* operators */
"||"                                 { return TOK_OR; }
"<"                                  { return TOK_LESS; }
">"                                  { return TOK_GREAT; }
"<="                                 { return TOK_LEQ; }
">="                                 { return TOK_GREQ; }
"!="                                 { return TOK_NEQ; }
"=="                                 { return TOK_EQ; }
"+"                                  { return TOK_PLUS; }
"-"                                  { return TOK_MINUS; }
"*"                                  { return TOK_MULT; }
"/"                                  { return TOK_DIV; }
   
"class"                              { return KW_CLASS; }                                /* keywords */
"main"                               { return KW_MAIN; }
"public"                             { return KW_PUBLIC; }
"static"                             { return KW_STATIC; }
"void"                               { return KW_VOID; }
"new"                                { return KW_NEW; }
"true"                               { return KW_TRUE; }
"false"                              { return KW_FALSE; }
"int"                                { return KW_INT; }
"boolean"                            { return KW_BOOLEAN; }
"String"                             { return KW_STRING; }
"if"                                 { return KW_IF; }
"else"                               { return KW_ELSE; }
"return"                             { return KW_RETURN; }
"while"                              { return KW_WHILE; }
"length"                             { return KW_LENGTH; }
"System.out.println"                 { return KW_SYSPLN; }
"System.out.print"                   { return KW_SYSP; }

[a-zA-Z]+[a-zA-Z0-9_]*               { return TOK_ID; }                                  /* identifiers */

[0-9]+                               { return LIT_INT; }                                 /* literals */
"\""([a-zA-Z0-9_]|"\\\"")*"\""       { return LIT_STRING; } // needs adjustments to accomodate escape characters

"."                                  { return TOK_DOT; }                                 /* other terminals */
","                                  { return TOK_COMMA; }
";"                                  { return TOK_SEMICOLON; }
"{"                                  { return TOK_OPENBRACE; }
"}"                                  { return TOK_CLOSEBRACE; }
"("                                  { return TOK_OPENPAR; }
")"                                  { return TOK_CLOSEPAR; }
"["                                  { return TOK_OPENBRACK; }
"]"                                  { return TOK_CLOSEBRACK; }        
"="                                  { return TOK_ASSIGN; }
         
.                                    { syntax_error(); }                                 /* all other characters */
         
<<EOF>>                              { return TOK_EOF; }

%%

// yyin is the input stream for lex, not providing a file defaults to
// standard input
void set_instream(FILE *file) {
  yyin = file;
}