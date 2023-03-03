#include "typecheck.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int num_errors = 0;
int num_entries = 0;
struct SymbolTableEntry *symbol_table[50];

static void report_type_violation(int line_number) {
    fprintf(stderr, "Type Violation in Line %d\n", line_number);
}

// Begin type checking from root nonterminal
void checkProgram(struct ASTNode * program) {
    num_entries = 0;
    checkMain(program->children[program->num_children-1]);
}

// Check the main nonterminal 
void checkMain(struct ASTNode * mainClass){
    char * nameOfClass = mainClass -> data.value.string_value;

    checkStaticVarDeclList(mainClass->children[0]);
    checkStaticMethodDeclList(mainClass->children[1]);
    checkStatementList(mainClass->children[2]);
}

// Check the available static var decl lists (nullable)
void checkStaticVarDeclList(struct ASTNode* staticVarDeclList) {
    enum NodeType staticVarDeclListType = staticVarDeclList -> node_type;
    if (staticVarDeclListType == NODETYPE_NULLABLE) return;

    struct ASTNode * nextStaticVarDeclList = staticVarDeclList -> children[0];
    struct ASTNode * staticVarDecl = staticVarDeclList -> children[1];

    checkStaticVarDeclList(nextStaticVarDeclList);
    checkStaticVarDecl(staticVarDecl);
}

// Check the available static method decl lists (nullable)
void checkStaticMethodDeclList(struct ASTNode * staticMethodDeclList) {
    enum NodeType staticMethodDeclListType = staticMethodDeclList -> node_type;
    if (staticMethodDeclListType == NODETYPE_NULLABLE) return;
    
    struct ASTNode * nextStaticMethodDeclList = staticMethodDeclList -> children[0];
    struct ASTNode * staticMethodDecl = staticMethodDeclList -> children[1];

    checkStaticMethodDeclList(nextStaticMethodDeclList);
    checkStaticMethodDecl(staticMethodDecl);
}

// Check the available statement lists (nullable)
void checkStatementList(struct ASTNode* statementList) {
    enum NodeType statementListType = statementList -> node_type;
    if (statementListType == NODETYPE_NULLABLE) return;

    struct ASTNode * nextStatementList = statementList -> children[0];
    struct ASTNode * statement = statementList -> children[1];

    checkStatementList(nextStatementList);
    checkStatement(statement);
}

// Check the given static var decl
void checkStaticVarDecl(struct ASTNode* staticVarDecl) {
    struct ASTNode * varDecl = staticVarDecl -> children[0];
    checkVarDecl(varDecl);
}

// Check variable declarations and all exp declarations
void checkVarDecl(struct ASTNode* varDecl) {
    struct ASTNode * expDecl = varDecl -> children[1];
    struct ASTNode * expList = varDecl -> children[2];
    
    enum NodeType expDeclType = expDecl -> node_type;
    enum NodeType expListType = expList -> node_type;
    
    // Check the local expression declaration
    checkExpDecl(varDecl, varDecl, expDecl);

    // Check all expression declarations in the expression list
    while (expListType != NODETYPE_NULLABLE) {
        expDecl = expList -> children[1];
        checkExpDecl(varDecl, expList, expDecl);
        expList = expList -> children[2];
        expListType = expList -> node_type;
    }
}

// Check expression declaration for a given variable declaration
void checkExpDecl(struct ASTNode* varDecl, struct ASTNode* parent, struct ASTNode* expDecl) {
    enum DataType varType = varDecl -> children[0] -> data.type;
    enum NodeType expDeclType = expDecl -> node_type;
    char * id = parent -> data.value.string_value;
    bool typeViolationExists = false;

    if (expDeclType != NODETYPE_NULLABLE) {
        struct ASTNode * exp = expDecl -> children[0];
        enum DataType expType = exp -> data.type;

        if (expType != varType) {
            typeViolationExists = true;
            report_type_violation(varDecl -> line_no);
        }

        struct SymbolTableEntry * foundEntry = find_symbol(id);

        if (foundEntry) {
            typeViolationExists = true;
            report_type_violation(varDecl -> line_no);
            
            if (foundEntry -> type != varType) {
                foundEntry -> type = DATATYPE_UNDEFINED;
            }
        }

        if (!typeViolationExists) {
            add_to_symbol_table(id, expDecl -> data);
        }
    } else {
        struct SymbolTableEntry * foundEntry = find_symbol(id);

        if (foundEntry) {
            typeViolationExists = true;
            report_type_violation(varDecl -> line_no);
            
            if (foundEntry -> type != varType) {
                foundEntry -> type = DATATYPE_UNDEFINED;
            }
        }

        if (!typeViolationExists) {
            expDecl -> data.type = DATATYPE_UNDEFINED;
            add_to_symbol_table(id, expDecl -> data);
        }
    }
}

// Check the given static method decl
void checkStaticMethodDecl(struct ASTNode* staticMethodDecl) {
    struct ASTNode * statementList = staticMethodDecl -> children[2];

    // TODO (check function symbol table entry and statementlist [maybe return value typing as well])
    checkStatementList(statementList);
}

// Check the given statement
void checkStatement(struct ASTNode* statement){
    enum NodeType statementType = statement -> node_type;
    if (statementType == NODETYPE_PRINT || statementType == NODETYPE_PRINTLN) {
        // All undefined types (int, boolean, String) are printable.
        // Even if the expression is eventually undefined, no errors are
        // reported here - undefined type is due to other type violations.
    } else if (statementType == NODETYPE_VARDECL) {
        struct ASTNode * varDecl = statement -> children[0];
        checkVarDecl(varDecl);
    }
}






struct SymbolTableEntry * find_symbol(char* id){
    for (int i = 0; i < num_entries; ++i) {
        if(strcmp(id, symbol_table[i]->id) == 0){
            return symbol_table[i];
        }
    }
    return NULL;
}

void add_to_symbol_table(char* id, struct SemanticData data){
    struct SymbolTableEntry* entry = malloc(sizeof(struct SymbolTableEntry));
    entry->id =id;
    entry->type = data.type;
    symbol_table[num_entries] = entry;
    num_entries++;
}