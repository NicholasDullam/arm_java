#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H
#define MAX_SCOPED_CHILDREN 10
#define MAX_TABLE_SIZE 50

#include "node.h"

enum ScopeType { SCOPETYPE_GLOBAL, SCOPETYPE_METHOD, SCOPETYPE_LOCAL };

struct SymbolTableEntry {
    char * id;
    enum DataType type;
};

struct ScopeEntry {
    enum ScopeType type;
    struct ScopeEntry * parent;
    struct ScopeEntry * children[MAX_SCOPED_CHILDREN];
    struct SymbolTableEntry * symbol_table[MAX_TABLE_SIZE];
    int num_children;
    int num_entries;
};

// Create a new scope
void createScope(enum ScopeType type);
int addChildScope(struct ScopeEntry* parent, struct ScopeEntry * child);
int exitScope();

struct SymbolTableEntry * searchLocalScope(char* id);
struct SymbolTableEntry * searchMethodScope(char* id);
struct SymbolTableEntry * searchGlobalScope(char* id);

// Adds an entry to the symbol table.
int addToSymbolTable(char* id, struct SemanticData SemanticData);

// Looks for an entry in the symbol table with the given name.
// Returns NULL if there is no such entry.
struct SymbolTableEntry * findSymbol(struct ScopeEntry * scope, char* id);

void checkProgram(struct ASTNode* program);
void checkMain(struct ASTNode* mainClass);

void checkStaticVarDeclList(struct ASTNode* staticVarDeclList);
void checkStaticMethodDeclList(struct ASTNode* staticMethodDeclList);
void checkStatementList(struct ASTNode* statementList);

void checkStaticVarDecl(struct ASTNode* staticVarDecl);
void checkVarDecl(struct ASTNode* varDecl);
void checkExpDecl(struct ASTNode* varDecl, struct ASTNode* parent, struct ASTNode* expDecl);
void checkStaticMethodDecl(struct ASTNode* staticMethodDecl);
void checkStatement(struct ASTNode* statement);

extern int num_errors;
extern int num_entries;

#endif
