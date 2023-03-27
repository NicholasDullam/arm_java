#ifndef CODE_GEN_H
#define CODE_GEN_H

#include "node.h"
#include "typecheck.h"

/*
    All general codegen functions
*/

void genProgram(struct ASTNode * program, char * fileName);
void genMain(struct ASTNode * mainClass);
void genStaticVarDeclList(struct ASTNode * staticVarDeclList);
void genStaticMethodDeclList(struct ASTNode * staticMethodDeclList);
void genStatementList(struct ASTNode * statementList);
void genStatement(struct ASTNode * statement);
void genStaticMethodDecl(struct ASTNode * staticMethodDecl);
void genFormalList(struct ASTNode * formalList);
void genStaticVarDecl(struct ASTNode * staticVarDecl);
void genVarDecl(struct ASTNode * varDecl);
void genMethodCall(struct ASTNode * methodCall);
void genExpDecl(struct ASTNode * expDecl);
void genExp(struct ASTNode * exp);
void genTerm(struct ASTNode * term);
void genFactor(struct ASTNode * factor);

/*
    Final run-through and eval functions
*/

void genMethodInit(struct ASTNode * node, char * id);
void genMethodEnd(struct ASTNode * node);
void genMethodVars(struct ScopeEntry * scope, char * ids[], int count);
void genLocalVars(struct ScopeEntry * scope, char * ids[], int count);
void genTraversal(struct ASTNode * parent, struct ASTNode * curr);
void genToFile(char * instructions[], int numInstructions, char * fileName);

/*
    General instruction helper functions
*/

char * createInstruction(char * instruction);
void insertInstructions(struct ASTNode * node, char * instructions[], int numInstructions);
void appendInstructions(struct ASTNode * node, char * instructions[], int numInstructions);

#endif