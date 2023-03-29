#ifndef CODE_GEN_H
#define CODE_GEN_H

#define MAX_INSTRUCTIONS 10000

#include "node.h"
#include "typecheck.h"

extern struct InstructionEntry * instructionHead;

enum ResponseType {
    RESPONSE_TYPE_GLOBAL,
    RESPONSE_TYPE_LOCAL,
    RESPONSE_TYPE_TEMP
};

struct InstructionEntry {
    char * instructions[MAX_INSTRUCTIONS];
    struct ScopeEntry * scope;
    struct ASTNode * node;
    struct InstructionEntry * children[MAX_SCOPED_CHILDREN];
    struct InstructionEntry * parent;
    enum ResponseType response_type;
    char * id;
    int temp_id;
    int num_child;
    int num_children;
    int num_instructions;
};

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
void genTraversal(struct InstructionEntry * parent, struct InstructionEntry * curr);
void genToFile(char * instructions[], int numInstructions, char * fileName);

/*
    General instruction helper functions
*/

char * createInstruction(char * instruction);
void insertInstruction(struct InstructionEntry * instructionScope, char * instructions, int start);
void appendInstructions(struct ASTNode * node, char * instructions[], int numInstructions);

/*
    New instructions helper functions
*/

void addToInstructionEntry(char * instruction);
void createInstructionScope(struct ASTNode * node, struct ScopeEntry * scope);
void addChildInstructionScope(struct InstructionEntry * parent, struct InstructionEntry * child);
void exitInstructionScope();

#endif