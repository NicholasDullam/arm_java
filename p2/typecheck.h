#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H

#include "node.h"

struct SymbolTableEntry{
    char * id;
    enum DataType type;
};

// Adds an entry to the symbol table.
void add_to_symbol_table(char* id, struct SemanticData SemanticData);

// Looks for an entry in the symbol table with the given name.
// Returns NULL if there is no such entry.
struct SymbolTableEntry * find_symbol(char* id);

void checkProgram(struct ASTNode* program);
void checkMain(struct ASTNode* mainClass);

void checkStaticMethodDeclList(struct ASTNODE* staticMethodDeclList);
void checkStaticVarDeclList(struct ASTNode* staticVarDeclList);
void checkStatementList(struct ASTNode* statementList);

void checkStaticMethodDecl(struct ASTNODE* staticMethodDecl);
void checkStaticVarDecl(struct ASTNode* staticVarDecl);
void checkStatement(struct ASTNode* statement);

extern int num_errors;
extern int num_entries;

#endif
