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

void checkStaticVarDeclList(struct ASTNode* staticVarDeclList);
void checkStaticMethodDeclList(struct ASTNode* staticMethodDeclList);
void checkStatementList(struct ASTNode* statementList);

void checkStaticVarDecl(struct ASTNode* staticVarDecl);
void checkStaticMethodDecl(struct ASTNode* staticMethodDecl);
void checkStatement(struct ASTNode* statement);

extern int num_errors;
extern int num_entries;

#endif
