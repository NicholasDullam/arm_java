#include "typecheck.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int num_errors = 0;

struct ScopeEntry * head = NULL;

static void reportTypeViolation(int line_number) {
    fprintf(stderr, "Type Violation in Line %d\n", line_number);
}

// Begin type checking from root nonterminal
void checkProgram(struct ASTNode* program) {
    createScope(SCOPETYPE_GLOBAL);
    checkMain(program->children[program->num_children-1]);
}

// Check the main nonterminal 
void checkMain(struct ASTNode* mainClass){
    char * argName = mainClass -> data.value.string_value;
    
    // May separate main function from class so ID is properly reflected
    
    // Run through static methods for forward references first

    checkStaticVarDeclList(mainClass->children[0]);
    checkStaticMethodDeclList(mainClass->children[1]);

    createScope(SCOPETYPE_METHOD);
    //addToSymbolTable(argName, mainClass -> data); // note we need to handle index typing
    createScope(SCOPETYPE_LOCAL);

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

        // may need to check expression here so that type is reflective of the final result

        enum DataType expType = exp -> data.type;

        if (expType != varType) {
            typeViolationExists = true;
            reportTypeViolation(varDecl -> line_no);
        }

        struct SymbolTableEntry * foundEntry = searchMethodScope(id);

        if (foundEntry) {
            typeViolationExists = true;
            reportTypeViolation(varDecl -> line_no);
            
            if (foundEntry -> type != varType) {
                foundEntry -> type = DATATYPE_UNDEFINED;
            }
        }

        if (!typeViolationExists) {
            addToSymbolTable(id, ENTRYTYPE_VAR, expDecl -> data.type, expDecl -> data);
        }
    } else {
        struct SymbolTableEntry * foundEntry = searchMethodScope(id);

        if (foundEntry) {
            typeViolationExists = true;
            reportTypeViolation(varDecl -> line_no);
            
            if (foundEntry -> type != varType) {
                foundEntry -> type = DATATYPE_UNDEFINED;
            }
        }

        if (!typeViolationExists) {
            expDecl -> data.type = DATATYPE_UNDEFINED;
            addToSymbolTable(id, ENTRYTYPE_VAR, expDecl -> data.type, expDecl -> data);
        }
    }
}

// Check the given expression
void checkExp(struct ASTNode* exp) {

}

// Check the given static method decl
void checkStaticMethodDecl(struct ASTNode* staticMethodDecl) {
    struct ASTNode * formalList = staticMethodDecl -> children[1];
    struct ASTNode * statementList = staticMethodDecl -> children[2];

    createScope(SCOPETYPE_METHOD);
    checkFormalList(formalList);
    createScope(SCOPETYPE_LOCAL);

    // TODO (check function symbol table entry and statementlist [maybe return value typing as well])
    checkStatementList(statementList);
}

void checkFormalList(struct ASTNode* formalList) {

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

/*
    All scope handler functions
*/

void createScope(enum ScopeType type) {
    struct ScopeEntry * child = malloc(sizeof(struct ScopeEntry));
    addChildScope(head, child);
    child -> parent = head;
    child -> type = type;
    child -> num_children = 0;
    child -> num_entries = 0;
    head = child;
}

int exitScope() {
    if (head -> parent) {
        head = head -> parent;
        return 0;
    } else {
        return -1;
    }
}

int addChildScope(struct ScopeEntry * parent, struct ScopeEntry * child) {
    if (!parent) return 0;
    if (parent -> num_children < MAX_NUM_CHILDREN - 1) {
        parent -> children[parent -> num_children] = child;
        parent -> num_children++;
        return 0;
    } else {
        return -1;
    }
}

struct SymbolTableEntry * searchLocalScope(char* id) {
    return findSymbol(head, id);
}

struct SymbolTableEntry * searchMethodScope(char* id) {
    struct ScopeEntry* curr = head;
    
    while (curr && curr -> type != SCOPETYPE_METHOD) {
        struct SymbolTableEntry* symbol = findSymbol(curr, id);
        if (symbol) return symbol;
        curr = curr -> parent;
    }

    return NULL;
}

struct SymbolTableEntry * searchGlobalScope(char* id) {
    struct ScopeEntry* curr = head;
    
    while (curr) {
        struct SymbolTableEntry* symbol = findSymbol(curr, id);
        if (symbol) return symbol;
        curr = curr -> parent;
    }

    return NULL;
}

/*
    All symbol table management functions
*/

struct SymbolTableEntry * findSymbol(struct ScopeEntry * scope, char * id){
    for (int i = 0; i < scope -> num_entries; ++i) {
        if(strcmp(id, scope -> symbol_table[i]->id) == 0){
            return scope -> symbol_table[i];
        }
    }
    return NULL;
}

struct SymbolTableEntry * addToSymbolTable(char * id, enum EntryType type, enum DataType data_type, struct SemanticData data){
    if (head -> num_entries < MAX_TABLE_SIZE - 1) {
        struct SymbolTableEntry* entry = malloc(sizeof(struct SymbolTableEntry));
        entry -> id = id;
        entry -> type = type;
        entry -> type = data_type;
        head -> symbol_table[head -> num_entries] = entry;
        head -> num_entries++;
        return entry;
    } else {
        return NULL;
    }
}