    // Operation grammars
    | Exp TOK_AND Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_OR Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_LESS Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_GREAT Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_LEQ Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_GREQ Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_EQ Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_NEQ Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }































Exp:  
    Exp TOK_PLUS Term {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Exp TOK_MINUS Term {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Term {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    };

Term:
    Term TOK_MULT Factor {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Term TOK_DIV Factor {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | Factor {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    };

Factor:
    TOK_NOT Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | TOK_PLUS Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | TOK_MINUS Exp {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        // fill out other semantics
    }
    | INTEGER_LITERAL {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        set_int_value($$, $1);
    }
    | STRING_LITERAL {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        set_string_value($$, $1);
    }
    | KW_TRUE {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        set_boolean_value($$, true);
    }
    | KW_FALSE {
        $$ = new_node(NODETYPE_LITERAL, yylineno);
        set_boolean_value($$, false);
    }
    | '(' Exp ')' {
        $$ = new_node(NODETYPE_EXP, yylineno);
        //$$ -> data.type = $2 -> data.type;
        add_child($$, $2);
    }
    | LeftValue {
        $$ = new_node(NODETYPE_LEFTVALUE, yylineno);
        add_child($$, $1);
    } 
    | LeftValue '.' KW_LENGTH {
        $$ = new_node(NODETYPE_LENGTH, yylineno);
        add_child($$, $1);
    }
    | MethodCall {
        $$ = new_node(NODETYPE_METHODCALL, yylineno);
        add_child($$, $1);
    }
    | KW_NEW PrimeType Index {
        $$ = new_node(NODETYPE_ARRAY, yylineno);
        add_child($$, $2);
        add_child($$, $3);
    };