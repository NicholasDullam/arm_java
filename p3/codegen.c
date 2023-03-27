#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "typecheck.h"
#include "codegen.h"
#include "node.h"

/*
    All general codegen functions
*/

void genProgram(struct ASTNode * program, char * fileName) {
    struct ASTNode * class = program -> children[0];
    genMain(class); // begin the codegen traversal of AST
    // perform post-order traversal of the AST and concat instructions
    genTraversal(NULL, program);
    genToFile(program -> data.instructions, program -> data.num_instructions, fileName); // push all instructions to file
}

void genMain(struct ASTNode * mainClass) {
    struct ASTNode * staticVarDeclList = mainClass -> children[0];
    struct ASTNode * staticMethodDeclList = mainClass -> children[1];
    struct ASTNode * statementList = mainClass -> children[2];
    
    genStaticVarDeclList(staticVarDeclList);                            // generate code for all static variable decl
    genStaticMethodDeclList(staticMethodDeclList);                      // generate code for all static method decl
    
    genMethodInit(statementList, "main");
    genStatementList(statementList);                                    // generate code for the given main function
    genMethodEnd(statementList);
}

void genStaticVarDeclList(struct ASTNode * staticVarDeclList) {
    if (staticVarDeclList -> node_type != NODETYPE_NULLABLE) {
        genStaticVarDeclList(staticVarDeclList -> children[0]);
        struct ASTNode * staticVarDecl = staticVarDeclList -> children[1];
        genStaticVarDecl(staticVarDecl);
    }
}

void genStaticMethodDeclList(struct ASTNode * staticMethodDeclList) {
    if (staticMethodDeclList -> node_type != NODETYPE_NULLABLE) {
        genStaticMethodDeclList(staticMethodDeclList -> children[0]);
        struct ASTNode * staticMethodDecl = staticMethodDeclList -> children[1];
        genStaticMethodDecl(staticMethodDecl);
    }
}

void genStatementList(struct ASTNode * statementList) {
    if (statementList -> node_type != NODETYPE_NULLABLE) {
        genStatementList(statementList -> children[0]);
        struct ASTNode * statement = statementList -> children[1];
        genStatement(statement);
    }
}

void genStatement(struct ASTNode * statement) {
    enum NodeType statementType = statement -> node_type;
    if (statementType == NODETYPE_VARDECL) {
        printf("Var Decl\n");
        genVarDecl(statement -> children[0]);
    }
}

void genStaticMethodDecl(struct ASTNode * staticMethodDecl) {
    genMethodInit(staticMethodDecl, staticMethodDecl -> data.value.string_value);
    genMethodEnd(staticMethodDecl);
}

void genFormalList(struct ASTNode * formalList) {
    if (formalList -> node_type != NODETYPE_NULLABLE) {
        // handle the variable and expression here
        genFormalList(formalList -> children[1]);        
    }
}

void genStaticVarDecl(struct ASTNode * staticVarDecl) {
    struct ASTNode * varDecl = staticVarDecl -> children[0];
    genVarDecl(varDecl);
}

void genVarDecl(struct ASTNode * varDecl) {
    struct ASTNode * expDecl = varDecl -> children[1];
    struct ASTNode * expList = varDecl -> children[2];
    genExpDecl(expDecl);
}

void genMethodCall(struct ASTNode * methodCall) {
    // add in handling before branching for method call
    // including the return symbolic register and return address
}

void genExpDecl(struct ASTNode * expDecl) {
    if (expDecl -> node_type != NODETYPE_NULLABLE) {
        printf("Expr Decl\n");
        genExp(expDecl -> children[0]);
    }
}

void genExp(struct ASTNode * exp) {
    enum NodeType expType = exp -> node_type;
    if (expType == NODETYPE_ADDOP) {
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        char * instructions[] = { 
            createInstruction(""),
            createInstruction("push {lr}\n"),
        }; 

        appendInstructions(exp, instructions, 2);
    } else if (expType == NODETYPE_TERM) {
        printf("Term\n");
        genTerm(exp -> children[0]);
    }
}

void genTerm(struct ASTNode * term) {
    enum NodeType termType = term -> node_type;
    if (termType == NODETYPE_FACTOR) {
        genFactor(term -> children[0]);
    }
}

void genFactor(struct ASTNode * factor) {
    enum NodeType factorType = factor -> node_type;
    if (factorType == NODETYPE_LITERAL) {
        printf("Literal\n");
        if (factor -> data.type == DATATYPE_INT) {
            char instruction[20];
            sprintf(instruction, "ldr $t1, #%d\n", factor -> data.value.int_value);
            char * instructions[] = { createInstruction(instruction) }; 
            appendInstructions(factor, instructions, 1);
        }
    } else if (factorType == NODETYPE_LEFTVALUE) {
        struct ASTNode * leftValue = factor -> children[0];
        printf("Left Value\n");
        struct SymbolTableEntry * foundEntry = searchGlobalScope(leftValue -> data.value.string_value);
        char instruction[20];
        sprintf(instruction, "ldr $t1, [sp, #%d]\n", 1);
        char * instructions[] = { createInstruction(instruction) }; 
        appendInstructions(factor, instructions, 1);
    }
}

/*
    Final run-through and eval functions
*/

void genMethodInit(struct ASTNode * node, char * id) {
    struct ScopeEntry * methodScope = findMethodScope(id);
    head = methodScope -> children[0]; // navigate to the method local scope for symbol table context
    char branch[strlen(id) + 3];
    sprintf(branch, "%s:\n", id);
    
    char * ids[50] = { NULL };
    genLocalVars(methodScope -> children[0], ids, 0);
    char localInit[50];

    for (int i = 0; i < 50; i++) {
        if (ids[i] == NULL) break;
        if (i == 0) sprintf(localInit, "@init %s", ids[i]);
        else sprintf(localInit, "%s, %s", localInit, ids[i]);
    }

    localInit[strlen(localInit) + 1] = '\0';
    localInit[strlen(localInit)] = '\n';

    char * instructions[] = { 
        createInstruction(branch),
        createInstruction("push {lr}\n"),
        //createInstruction(localInit) 
    }; 

    appendInstructions(node, instructions, 2);
}

void genMethodEnd(struct ASTNode * node) {
    char * instructions[] = { 
        createInstruction("pop {pc}\n\n"),
    }; 

    appendInstructions(node, instructions, 1);
    exitScope();
    exitScope();
}

void genMethodVars(struct ScopeEntry * scope, char * ids[], int count) {
    if (scope == NULL) {
        printf("Failed to find method scope\n");
        return;
    }

    for (int i = 0; i < scope -> num_entries; i++) {
        ids[count] = scope -> symbol_table[i] -> id;
        count++;
    }
} 

void genLocalVars(struct ScopeEntry * scope, char * ids[], int count) {
    if (scope == NULL) {
        printf("Failed to find method scope\n");
        return;
    }

    for (int i = 0; i < scope -> num_entries; i++) {
        ids[count] = scope -> symbol_table[i] -> id;
        count++;
    }
    
    // Check remaining scopes
    for (int i = 0; i < scope -> num_children; i++) {
        genLocalVars(scope -> children[i], ids, count);
    }
}

void genTraversal(struct ASTNode * parent, struct ASTNode * curr) {
    for (int i = 0; i < curr -> num_children; i++) {
        genTraversal(curr, curr -> children[i]);
    }

    if (parent == NULL) return;
    insertInstructions(parent, curr -> data.instructions, curr -> data.num_instructions);
}

void genToFile(char * instructions[], int numInstructions, char * fileName) {
    printf("Moving instructions to file\n");
    char fileNameNoExt[strlen(fileName) - 2]; // include length for null terminator
    strncpy(fileNameNoExt, fileName, strlen(fileName) - 4); // remove the java extension
    fileNameNoExt[strlen(fileName) - 4] = 's'; // add the assembly extensions
    fileNameNoExt[strlen(fileName) - 3] = '\0'; // add back the null terminator
    printf("Creating file %s\n", fileNameNoExt);
    FILE * fp = fopen(fileNameNoExt, "w"); // create the new file pointer
    for (int i = 0; i < numInstructions; i++) fwrite(instructions[i], 1, strlen(instructions[i]), fp);
    fclose(fp); // ensure the file pointer is closed before unmount
}

/*
    General instruction helper functions
*/

char * createInstruction(char * instruction) {
    char * reference = (char *) malloc(sizeof(char) * strlen(instruction));
    strcpy(reference, instruction);
    return reference;
}

void insertInstructions(struct ASTNode * node, char * instructions[], int numInstructions) {
    char * temp = NULL;    
    
    if (node -> data.num_instructions + numInstructions >= MAX_INSTRUCTIONS) return;
    for (int i = 0; i < numInstructions; i++) {
        char * curr = node -> data.instructions[i];
        if (i < numInstructions) node -> data.instructions[i] = instructions[i];
        int j = 0;
        while (curr) {
            temp = node -> data.instructions[i + j * numInstructions];
            node -> data.instructions[i + j * numInstructions] = curr;
            curr = temp;
            j++;
        }
    }

    node -> data.num_instructions += numInstructions;
}

void appendInstructions(struct ASTNode * node, char * instructions[], int numInstructions) {
    if (node -> data.num_instructions + numInstructions >= MAX_INSTRUCTIONS) return;
    for (int i = 0; i < numInstructions; i++) {
        node -> data.instructions[i + node -> data.num_instructions] = instructions[i];
    }
    node -> data.num_instructions += numInstructions;
}