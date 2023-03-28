#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "typecheck.h"
#include "codegen.h"
#include "node.h"

/*
    All general codegen functions
*/ 

struct InstructionEntry * instructionHead = NULL;
int offset = 0;
int depth = 0;

void genProgram(struct ASTNode * program, char * fileName) {
    struct ASTNode * class = program -> children[0];

    // Handle codegen traversal of AST
    genMain(class);

    // Post-process the instruction tree
    genTraversal(NULL, instructionHead);

    // Push all instructions to .s file 
    genToFile(instructionHead -> instructions, instructionHead -> num_instructions, fileName);
}

void genMain(struct ASTNode * mainClass) {
    struct ASTNode * staticVarDeclList = mainClass -> children[0];
    struct ASTNode * staticMethodDeclList = mainClass -> children[1];
    struct ASTNode * statementList = mainClass -> children[2];

    // Create final coalesce instruction entry
    createInstructionScope(mainClass, head);
    
    // Handle static variable instructions and .text section
    createInstructionScope(staticVarDeclList, head);
    createInstructionScope(staticVarDeclList, head);
    addToInstructionEntry(".section .text\n");
    addToInstructionEntry("printIntLn: .asciz \"%d\\n\"\n");
    addToInstructionEntry("printStringLn: .asciz \"%s\\n\"\n");
    addToInstructionEntry("printInt: .asciz \"%d\"\n");
    addToInstructionEntry("printString: .asciz \"%s\"\n");
    exitInstructionScope();
    genStaticVarDeclList(staticVarDeclList); 
    createInstructionScope(staticVarDeclList, head);
    addToInstructionEntry("\n.global main\n");     
    addToInstructionEntry(".balign 4\n\n");                            
    exitInstructionScope();
    exitInstructionScope();
    
    // Handle static method instructions
    genStaticMethodDeclList(staticMethodDeclList);                 

    // Handle main method instructions
    createInstructionScope(statementList, head);
    genMethodInit(statementList, "main");
    genStatementList(statementList);                                   
    genMethodEnd(statementList);
    exitInstructionScope();
}

void genStaticVarDeclList(struct ASTNode * staticVarDeclList) {
    if (staticVarDeclList -> node_type != NODETYPE_NULLABLE) {
        genStaticVarDeclList(staticVarDeclList -> children[0]);
        genStaticVarDecl(staticVarDeclList -> children[1]);
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
    if (statementType == NODETYPE_VARDECL) { // if the assignemtn operation does not return an offset (as in, an offset to a temp variable), just store what is found in r0 rather than loading into r0
        struct ASTNode * varDecl = statement -> children[0];
        createInstructionScope(varDecl, head);
        genVarDecl(varDecl);
        char instruction[60];
        sprintf(instruction, "str $t%d, %s @reconfigure to work with the rest\n", depth - 1, varDecl -> data.value.string_value);
        addToInstructionEntry(instruction);
        exitInstructionScope();
        depth = 0;
    } else if (statementType == NODETYPE_PRINT) {
        struct ASTNode * exp = statement -> children[0];
        createInstructionScope(statement, head);
        if (exp -> data.type == DATATYPE_INT) {
            addToInstructionEntry("ldr r0, =printInt\n");
        } else if (exp -> data.type == DATATYPE_STR) {
            addToInstructionEntry("ldr r0, =printString\n");
        }
        addToInstructionEntry("bl printf\n");
        exitInstructionScope();
    } else if (statementType == NODETYPE_PRINTLN) {
        struct ASTNode * exp = statement -> children[0];
        createInstructionScope(statement, head);
        if (exp -> data.type == DATATYPE_INT) {
            addToInstructionEntry("ldr r0, =printIntLn\n");
        } else if (exp -> data.type == DATATYPE_STR) {
            addToInstructionEntry("ldr r0, =printStringLn\n");
        }
        addToInstructionEntry("bl printf\n");
        exitInstructionScope();
    }
}

void genStaticMethodDecl(struct ASTNode * staticMethodDecl) {
    createInstructionScope(staticMethodDecl, head); // method instruction scope
    genMethodInit(staticMethodDecl, staticMethodDecl -> data.value.string_value);
    genMethodEnd(staticMethodDecl);
    exitInstructionScope(); // exit method instruction scope
}

void genStaticVarDecl(struct ASTNode * staticVarDecl) {
    createInstructionScope(staticVarDecl, head);
    struct ASTNode * varDecl = staticVarDecl -> children[0];

    // work-around for the time-being
    struct ASTNode * expDecl = varDecl -> children[1];
    struct ASTNode * exp = expDecl -> children[0];
    struct ASTNode * term = exp -> children[0];
    struct ASTNode * factor = term -> children[0];

    if (factor -> data.type == DATATYPE_INT) {
        char instruction[4];
        sprintf(instruction, "%d", factor -> data.value.int_value);
        addToInstructionEntry(varDecl -> data.value.string_value);
        addToInstructionEntry(": ");
        addToInstructionEntry(".word ");
        addToInstructionEntry(instruction);
        addToInstructionEntry("\n");
    } else if (factor -> data.type == DATATYPE_STR) {
        addToInstructionEntry(varDecl -> data.value.string_value);
        addToInstructionEntry(": ");
        addToInstructionEntry(".asciz ");
        addToInstructionEntry(factor -> data.value.string_value);
        addToInstructionEntry("\n");
    } 
    
    exitInstructionScope();
}

void genVarDecl(struct ASTNode * varDecl) {
    struct ASTNode * expDecl = varDecl -> children[1];
    struct ASTNode * expList = varDecl -> children[2]; // check this
    genExpDecl(expDecl);
}

void genMethodCall(struct ASTNode * methodCall) {
    enum NodeType methodCallType = methodCall -> node_type;
    if (methodCallType == NODETYPE_METHODCALL) {
        // add in handling before branching for method call
        // including the return symbolic register and return address
    }
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
        createInstructionScope(exp, head);
        genExp(nestedExp);
        genTerm(term);
        addToInstructionEntry("add r2, r0, r1\n");
        int newOffset = 4;
        char instruction[20];
        sprintf(instruction, "str r2, [sp, #%d]\n", newOffset);
        addToInstructionEntry(instruction);
        exitInstructionScope();
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

// make sure to use the offsets stored in the node value as reference for varDecl, and method calls

void genFactor(struct ASTNode * factor) {
    enum NodeType factorType = factor -> node_type;
    if (factorType == NODETYPE_LITERAL) {
        if (factor -> data.type == DATATYPE_INT) {
            createInstructionScope(factor, head);
            if (instructionHead -> num_child == 0) { // left child instructions
                char instruction[20];
                sprintf(instruction, "ldr r0, #%d\n", factor -> data.value.int_value);
                addToInstructionEntry(instruction);            
            } else { // right child instructions
                char instruction[20];
                sprintf(instruction, "ldr r1, #%d\n", factor -> data.value.int_value);
                addToInstructionEntry(instruction);     
            }
            exitInstructionScope();        
        }
    } else if (factorType == NODETYPE_LEFTVALUE) {
        createInstructionScope(factor, head);
        struct ASTNode * leftValue = factor -> children[0];
        struct SymbolTableEntry * foundEntry = searchGlobalScope(leftValue -> data.value.string_value);
        if (instructionHead -> num_child == 0) { // left child instructions
            char instruction[40];
            sprintf(instruction, "ldr r0, [sp, #%d] @replace with offsets\n", factor -> data.value.int_value); // replace with offsets assigned in local var prescreen
            addToInstructionEntry(instruction);            
        } else { // right child instructions
            char instruction[40];
            sprintf(instruction, "ldr r1, [sp, #%d] @replace with offsets\n", factor -> data.value.int_value); // replace with offsets assigned in local var prescreen
            addToInstructionEntry(instruction);     
        }
        exitInstructionScope();
    }
}

/*
    Final run-through and eval functions
*/

void genMethodInit(struct ASTNode * node, char * id) {
    struct ScopeEntry * methodScope = findMethodScope(id, head);
    if (!methodScope) return;
    head = methodScope -> children[0]; // navigate to the method local scope for symbol table context
    char branch[strlen(id) + 3];
    sprintf(branch, "%s:\n", id);
    createInstructionScope(node, methodScope); // create a config instruction scope
    addToInstructionEntry(branch);
    addToInstructionEntry("push {lr}\n");
    exitInstructionScope(); // exit the config instruction scope
 }

void genMethodEnd(struct ASTNode * node) {
    createInstructionScope(node, NULL); // method ending config instruction scope
    addToInstructionEntry("pop {pc}\n\n");
    exitInstructionScope(); // exit method ending config instruction scope
    exitInstructionScope(); // exit method instruction scope
    exitScope(); // exit local scope
    exitScope(); // exit method scope
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

void genTraversal(struct InstructionEntry * parent, struct InstructionEntry * curr) {
    for (int i = curr -> num_children - 1; i >= 0; i--) {
        genTraversal(curr, curr -> children[i]);
    }

    if (parent == NULL) return;
    for (int i = 0; i < curr -> num_instructions; i++) insertInstruction(parent, curr -> instructions[i], i);
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

void insertInstruction(struct InstructionEntry * instructionScope, char * instruction, int start) {
    if (instructionScope -> num_instructions + 1 >= MAX_INSTRUCTIONS) {
        printf("Hit max instructions for node\n");
        return;
    }

    int iterator = start;
    char * temp = NULL;    
    char * curr = instructionScope -> instructions[iterator];
    instructionScope -> instructions[iterator] = instruction;
    iterator++;

    while (curr) {
        temp = instructionScope -> instructions[iterator];
        instructionScope -> instructions[iterator] = curr;
        curr = temp;
        iterator++;
    }

    instructionScope -> num_instructions++;
}

/*
    New instruction helper functions
*/

void addToInstructionEntry(char * instruction) {
    char * reference = (char *) malloc(sizeof(char) * strlen(instruction));
    strcpy(reference, instruction);
    instructionHead -> instructions[instructionHead -> num_instructions] = reference;
    instructionHead -> num_instructions++;
}

void createInstructionScope(struct ASTNode * node, struct ScopeEntry * scope) {
    struct InstructionEntry * child = malloc(sizeof(struct InstructionEntry));
    memset(child, 0, sizeof(struct InstructionEntry));
    addChildInstructionScope(instructionHead, child);
    child -> parent = instructionHead;
    child -> scope = scope;
    child -> node = node;
    child -> num_instructions = 0;
    child -> num_children = 0;
    if (child -> parent) child -> num_child = child -> parent -> num_children - 1;
    instructionHead = child;
}

void addChildInstructionScope(struct InstructionEntry * parent, struct InstructionEntry * child) {
    if (parent && parent -> num_children < MAX_SCOPED_CHILDREN) {
        parent -> children[parent -> num_children] = child;
        parent -> num_children++;
    }
}

void exitInstructionScope() {
    if (instructionHead -> parent) instructionHead = instructionHead -> parent;
}