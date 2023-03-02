#include "typecheck.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int num_errors = 0;
int num_entries = 0;
struct SymbolTableEntry *symbol_table[50];

static void report_type_violation(int line_number) {
    fprintf(stderr, "Type Violation in Line %d", line_number);
}

void checkProgram(struct ASTNode * program){
    num_entries = 0;
    checkMain(program->children[program->num_children-1]);
}

void checkMain(struct ASTNode * mainClass){
    char * nameOfClass = mainClass -> data.value.string_value;

    checkStaticVarDeclList(mainClass->children[0]);
    checkStaticMethodDeclList(mainClass->children[1]);
    checkStatementList(mainClass->children[2]);
}

void checkStaticMethodDeclList(struct ASTNode * staticMethodDeclList) {
    enum NodeType staticMethodDeclListType = staticMethodDeclList -> node_type;
    if (staticMethodDeclListType === NODETYPE_NULLABLE) return;
    
    struct ASTNode * staticMethodDecl = staticMethodDeclList -> children[0];
    struct ASTNode * nextStaticMethodDeclList = staticMethodDeclList -> children[1];

    // check ind methoddecl
    checkStaticVarDeclList(nextStaticMethodDeclList)
}

void checkStaticVarDeclList(struct ASTNode* staticVarDeclList) {
    enum NodeType staticVarDeclListType = staticVarDeclList -> node_type;
    if (staticVarDeclListType == NODETYPE_NULLABLE) return;

    struct ASTNode * staticVarDecl = staticVarDeclList -> children[0];
    struct ASTNode * nextStaticVarDeclList = staticVarDeclList -> children[1];

    // check ind vardecl
    checkStaticVarDeclList(nextStaticVarDeclList)
}

// Check the available statement lists (nullable)
void checkStatementList(struct ASTNode* statementList) {
    enum NodeType statementListType = statementList -> node_type;
    if (statementListType == NODETYPE_NULLABLE) return;

    struct ASTNode * statement = statementList -> children[0];
    struct ASTNode * nextStatementList = statementList -> children[1];
    
    checkStatement(statement);
    checkStatementList(nextStatementList);
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
        enum DataType var_type = varDecl ->children[0]->data.type;
        enum DataType expr_type = varDecl ->children[1]->data.type;
        char * id = varDecl->data.value.string_value;
        
        bool type_violation_exists = false;
        // Reports an error if the variable initializer expression has a
        // different type.
        if (var_type == expr_type) {
            type_violation_exists = true;
            report_type_violation(/*TODO*/-1);
        }
        // Reports an error if the declared variable is declared before (i.e.,
        // already exists in the symbol table).
        struct SymbolTableEntry * found_entry = find_symbol(id);
        if (found_entry != NULL) {
            type_violation_exists = true;
            report_type_violation(/*TODO*/-1);
            
            // Changes the type of the variable to undefined, unless the 
            // redefinition is the same type as the existing one.
            if (found_entry->type != var_type) 
                found_entry->type = DATATYPE_UNDEFINED;
        }
        if (!type_violation_exists) {
            add_to_symbol_table(id, varDecl->children[1]->data);
        };
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