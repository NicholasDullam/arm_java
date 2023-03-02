%{
#include <stdio.h>
#include <string.h>
#include "typecheck.h"
#include "node.h"
void yyerror(char *);

extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;

struct ASTNode* root;
%}

// Declares all variants of semantic values. Yacc/Bison copies all variants
// to the generated header file (y.tab.h) enclosed in a C-language union
// declaration, named `YYSTYPE`. Check out the header file to see it.
%union {
    struct ASTNode* node;
    int integer;
    char * string;
}

// Declares tokens. In the generated y.tab.h file, each token gets declared as 
// a enum constant and assigned with a unique number. These enum constants are
// used in the lex file, returned by `yylex()` to denote the symbolic tokens.

// These keyword-like tokens doesn't need to have a semantic value.

%token KW_BOOLEAN KW_CLASS KW_FALSE KW_INT MAIN KW_PUBLIC KW_TRUE KW_VOID 
%token KW_IF KW_ELSE KW_RETURN KW_WHILE KW_LENGTH KW_STATIC KW_STRING 
%token KW_NEW KW_PRIVATE

%token SYSTEM_OUT_PRINT SYSTEM_OUT_PRINTLN 

// These tokens have additional information aside from what kind of token it
// is, so they carry semantic information.

// Left hand non-terminals. They are all associated to the `node` variant
// declared in the %union section, which is of type `ASTNode *`.

%type <node> Program MainClass VarDecl Statement Exp ExpList FormalList
%type <node> ExpTail ExpDecl Type PrimeType LeftValue Index MethodCall
%type <node> StaticVarDecl StaticVarDeclList StaticMethodDecl StaticMethodDeclList VarDeclExpList 

%token <integer> INTEGER_LITERAL
%token <string> STRING_LITERAL ID

%start Program

%%

Program:                
    MainClass {   
        $$ = new_node(NODETYPE_PROGRAM);
        root = $$;
        add_child($$, $1);
    };

MainClass: 
    KW_CLASS ID '{'
        StaticVarDeclList 
        KW_PUBLIC KW_STATIC KW_VOID MAIN '(' KW_STRING '[' ']' ID ')' '{' Statement '}'
    '}'
    {
        $$ = new_node(NODETYPE_MAINCLASS);
        set_string_value($$, $2);
        add_child($$, $16);
    };

/*
    All variable declaration grammars
*/

VarDecl:
    Type ID '=' Exp ';' {
        $$ = new_node(NODETYPE_VARDECL);
        set_string_value($$, $2);
        add_child($$, $1);
        add_child($$, $4);
    };

StaticVarDecl:
    KW_PRIVATE KW_STATIC Type ID ExpDecl VarDeclExpList ';' {
        $$ = new_node(NODETYPE_STATICVARDECL);
        set_string_value($$, $4);
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $6);
    }

StaticVarDeclList:
    StaticVarDecl StaticVarDeclList {
        $$ = new_node(NODETYPE_STATICVARDECLLIST);
        add_child($$, $1);
        add_child($$, $2);
    }
    | {
        $$ = new_node(NODETYPE_STATICVARDECLLIST);
    }

VarDeclExpList:
    ',' ID ExpDecl VarDeclExpList {
        $$ = new_node(NODETYPE_VARDECLEXPLIST);
        set_string_value($$, $2);
        add_child($$, $3);
        add_child($$, $4);
    }
    |  {
        $$ = new_node(NODETYPE_VARDECLEXPLIST);
    }
     
Statement:              
    VarDecl {
        $$ = new_node(NODETYPE_VARDECL);
        add_child($$, $1);
    }
    | SYSTEM_OUT_PRINTLN '(' Exp ')' ';' {
        $$ = new_node(NODETYPE_PRINTLN);
        add_child($$, $3);
    }
    | SYSTEM_OUT_PRINT '(' Exp ')' ';' {
        $$ = new_node(NODETYPE_PRINT);
        add_child($$, $3);
    };

LeftValue:
    ID {
        $$ = new_node(NODETYPE_LEFTVALUE);
        set_string_value($$, $1);
    }
    | LeftValue '[' Exp ']' {
        $$ = new_node(NODETYPE_LEFTVALUE);
        add_child($$, $1);
        add_child($$, $3);
    };

Index: 
    '[' Exp ']' {
        $$ = new_node(NODETYPE_INDEX);
        add_child($$, $2);
    }
    | Index '[' Exp ']' {
        $$ = new_node(NODETYPE_INDEX);
        add_child($$, $1);
        add_child($$, $3);
    };

/*
    All typing related grammars
*/

Type: 
    PrimeType {
        $$ = new_node(NODETYPE_TYPE);
        $$ -> data.type = $1 -> data.type;
        add_child($$, $1);
    }
    | Type '[' ']' {
        $$ = new_node(NODETYPE_TYPE);
        $$ -> data.type = $1 -> data.type;
        add_child($$, $1);
    };

PrimeType:                   
    KW_INT {
        $$ = new_node(NODETYPE_PRIMETYPE);
        $$ -> data.type = DATATYPE_INT;
    }
    | KW_BOOLEAN {
        $$ = new_node(NODETYPE_PRIMETYPE);
        $$ -> data.type = DATATYPE_BOOLEAN;
    }
    | KW_STRING {
        $$ = new_node(NODETYPE_PRIMETYPE);
        $$ -> data.type = DATATYPE_STR;
    };  

// Can opt to make two separate grammars here for MethodCall to divert the ExpList nullable grammar
MethodCall:
    ID '(' ExpList ')' {
        $$ = new_node(NODETYPE_METHODCALL);
        set_string_value($$, $1);
        add_child($$, $3);
    };     

/*
    All expression based grammars
*/

Exp:                    
    INTEGER_LITERAL {
        $$ = new_node(NODETYPE_EXP);
        set_int_value($$, $1);
    }
    | STRING_LITERAL {
        $$ = new_node(NODETYPE_EXP);
        set_string_value($$, $1);
    }
    | KW_TRUE {
        $$ = new_node(NODETYPE_EXP);
        set_boolean_value($$, true);
    }
    | KW_FALSE {
        $$ = new_node(NODETYPE_EXP);
        set_boolean_value($$, false);
    }
    | '(' Exp ')' {
        $$ = new_node(NODETYPE_EXP);
        add_child($$, $2);
    }
    | LeftValue {
        $$ = new_node(NODETYPE_EXP);
        add_child($$, $1);
    } 
    | LeftValue '.' KW_LENGTH {
        $$ = new_node(NODETYPE_EXP);
        add_child($$, $1);
    }
    | MethodCall {
        $$ = new_node(NODETYPE_EXP);
        add_child($$, $1);
    }
    | KW_NEW PrimeType Index {
        $$ = new_node(NODETYPE_EXP);
        add_child($$, $2);
        add_child($$, $3);
    }
    ;

ExpDecl:
    '=' Exp {
        $$ = new_node(NODETYPE_EXPDECL);
        add_child($$, $2);
    }
    | {
        $$ = new_node(NODETYPE_EXPDECL);
    }

ExpList:
    Exp ExpTail {
        $$ = new_node(NODETYPE_EXPLIST);
        add_child($$, $1);
        add_child($$, $2);
    }
    | Exp {
        $$ = new_node(NODETYPE_EXPLIST);
        add_child($$, $1);
    }
    | {
        $$ = new_node(NODETYPE_EXPLIST);
    };

ExpTail:
    ',' Exp ExpTail {
        $$ = new_node(NODETYPE_EXPTAIL);
        add_child($$, $2);
        add_child($$, $3);
    }
    | {
        $$ = new_node(NODETYPE_EXPTAIL);
    };
%%

void yyerror(char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

int main(int argc, char* argv[] )
{
    yyin = fopen( argv[1], "r" );

    // Checks for syntax errors and constructs AST
    if (yyparse() != 0)
        return 1;

    // Traverse the AST to check for semantic errors if no syntac errors
    checkProgram(root);
    
    return 0;
}
