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
int tempCount = 0;
int offset = 0;

// Generate the 3AC for the program, alongside post-processing and write to file
void genProgram(struct ASTNode * program, char * fileName) {
    struct ASTNode * class = program -> children[0];

    // Handle codegen traversal of AST
    genMain(class);

    // Post-process the instruction tree
    genTraversal(NULL, instructionHead);

    // Push all instructions to .s file 
    genToFile(instructionHead -> instructions, instructionHead -> num_instructions, fileName);
}

// Generate the 3AC for the main class
void genMain(struct ASTNode * mainClass) {
    struct ASTNode * staticVarDeclList = mainClass -> children[0];
    struct ASTNode * staticMethodDeclList = mainClass -> children[1];
    struct ASTNode * statementList = mainClass -> children[2];

    // Create final coalesce instruction entry
    createInstructionScope(mainClass, head);
    
    // Handle static variable instructions and .text section
    createInstructionScope(staticVarDeclList, head);
    createInstructionScope(staticVarDeclList, head);
    addToInstructionEntry(".section .data\n");
    addToInstructionEntry("printIntLn: .asciz \"%d\\n\"\n");
    addToInstructionEntry("printStringLn: .asciz \"%s\\n\"\n");
    addToInstructionEntry("printInt: .asciz \"%d\"\n");
    addToInstructionEntry("printString: .asciz \"%s\"\n");
    exitInstructionScope();
    genStaticVarDeclList(staticVarDeclList); 
    createInstructionScope(staticVarDeclList, head);
    addToInstructionEntry("\n.section .text\n");     
    addToInstructionEntry(".global main\n");     
    addToInstructionEntry(".balign 4\n\n");                            
    exitInstructionScope();
    exitInstructionScope();
    
    // Handle static method instructions
    genStaticMethodDeclList(staticMethodDeclList);                 

    // Handle main method instructions
    createInstructionScope(statementList, head);
    genMethodInit(statementList, "main");
    genStatementList(statementList);                                   
    genMethodEnd(statementList, "main");
    exitInstructionScope();
}

// Generate 3AC for full static variable declaration list
void genStaticVarDeclList(struct ASTNode * staticVarDeclList) {
    if (staticVarDeclList -> node_type != NODETYPE_NULLABLE) {
        genStaticVarDeclList(staticVarDeclList -> children[0]);
        genStaticVarDecl(staticVarDeclList -> children[1]);
    }
}

// Generaate 3AC for full static method list
void genStaticMethodDeclList(struct ASTNode * staticMethodDeclList) {
    if (staticMethodDeclList -> node_type != NODETYPE_NULLABLE) {
        genStaticMethodDeclList(staticMethodDeclList -> children[0]);
        struct ASTNode * staticMethodDecl = staticMethodDeclList -> children[1];
        genStaticMethodDecl(staticMethodDecl);
    }
}

// Generate 3AC for full statement list
void genStatementList(struct ASTNode * statementList) {
    if (statementList -> node_type != NODETYPE_NULLABLE) {
        genStatementList(statementList -> children[0]);
        struct ASTNode * statement = statementList -> children[1];
        genStatement(statement);
    }
}

// Generate 3AC for statement trees
void genStatement(struct ASTNode * statement) {
    enum NodeType statementType = statement -> node_type;
    if (statementType == NODETYPE_VARDECL) { // if the assignemtn operation does not return an offset (as in, an offset to a temp variable), just store what is found in r0 rather than loading into r0
        struct ASTNode * varDecl = statement -> children[0];
        createInstructionScope(varDecl, head);

        // Incorporate the nested expression instructions into the current instruction scope
        genVarDecl(varDecl);
        
        // Create the instruction for the variable declaration
        char instruction[60];
        sprintf(instruction, "str $t%d, %s @reconfigure to work with the rest\n", tempCount, varDecl -> data.value.string_value);
        addToInstructionEntry(instruction);

        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> id = varDecl -> data.value.string_value;

        tempCount++;
        exitInstructionScope();
    } else if (statementType == NODETYPE_PRINT) {
        struct ASTNode * exp = statement -> children[0];
        createInstructionScope(statement, head);

        // Incorporate the nested expression instructions into the current instruction scope
        genExp(exp);

        // Change the global reference depending on the type of expression
        if (exp -> data.type == DATATYPE_INT) {
            addToInstructionEntry("ldr r0, =printInt\n");
        } else if (exp -> data.type == DATATYPE_STR) {
            addToInstructionEntry("ldr r0, =printString\n");
        }

        // Create an instruction to load the expr into the second register
        char instruction[60];
        sprintf(instruction, "ldr r1, $t%d\n", instructionHead -> children[0] -> temp_id);
        addToInstructionEntry(instruction);        
        
        // Create the branching instruction for the statement
        addToInstructionEntry("bl printf\n");

        instructionHead -> response_type = RESPONSETYPE_TEMP;

        exitInstructionScope();
    } else if (statementType == NODETYPE_PRINTLN) {
        struct ASTNode * exp = statement -> children[0];
        createInstructionScope(statement, head);
        
        // Incorporate the nested expression instructions into the current instruction scope
        genExp(exp);

        // Change the global reference depending on the type of expression
        if (exp -> data.type == DATATYPE_INT) {
            addToInstructionEntry("ldr r0, =printIntLn\n");
        } else if (exp -> data.type == DATATYPE_STR) {
            addToInstructionEntry("ldr r0, =printStringLn\n");
        }

        // Create an instruction to load the expr into the second register
        char instruction[60];
        sprintf(instruction, "ldr r1, $t%d\n", instructionHead -> children[0] -> temp_id);
        addToInstructionEntry(instruction);

        // Create the branching instruction for the statement
        addToInstructionEntry("bl printf\n");

        instructionHead -> response_type = RESPONSETYPE_TEMP;

        exitInstructionScope();
    } else if (statementType == NODETYPE_METHODCALL) {
        genMethodCall(statement -> children[0]);
    } else if (statementType == NODETYPE_RETURN) {
        createInstructionScope(statement, head);

        // Incorporate the nested expression instructions into the current instruction scope
        genExp(statement -> children[0]);

        // Create an instruction for loading the exp into the first register
        struct InstructionEntry * arg = instructionHead -> children[0];
        char instruction[20];
        sprintf(instruction, "ldr r0, $t%d\n", arg -> temp_id);
        addToInstructionEntry(instruction);

        instructionHead -> response_type = RESPONSETYPE_TEMP;

        exitInstructionScope();
    }
}

// Generate 3AC for static method declarations
void genStaticMethodDecl(struct ASTNode * staticMethodDecl) {
    createInstructionScope(staticMethodDecl, head); // method instruction scope
    genMethodInit(staticMethodDecl, staticMethodDecl -> data.value.string_value);
    genStatementList(staticMethodDecl -> children[2]);
    genMethodEnd(staticMethodDecl, staticMethodDecl -> data.value.string_value);
    exitInstructionScope(); // exit method instruction scope
}

// Generate 3AC for static variable declarations
void genStaticVarDecl(struct ASTNode * staticVarDecl) {
    createInstructionScope(staticVarDecl, head);
    struct ASTNode * varDecl = staticVarDecl -> children[0];

    // Work-around for the time-being
    struct ASTNode * expDecl = varDecl -> children[1];
    struct ASTNode * exp = expDecl -> children[0];
    struct ASTNode * term = exp -> children[0];
    struct ASTNode * factor = term -> children[0];

    // Change the symbol table entry to record global variables
    struct SymbolTableEntry * found = searchGlobalScope(varDecl -> data.value.string_value);
    found -> var_type = VARTYPE_GLOBAL;

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

// Generate 3AC for variable declarations
void genVarDecl(struct ASTNode * varDecl) {
    struct ASTNode * expDecl = varDecl -> children[1];
    struct ASTNode * expList = varDecl -> children[2]; // check this
    genExpDecl(expDecl);
}

// Generate 3AC for method calls
void genMethodCall(struct ASTNode * methodCall) {
    enum NodeType methodCallType = methodCall -> node_type;
    if (methodCallType == NODETYPE_METHODCALL) {
        createInstructionScope(methodCall, head);
        struct SymbolTableEntry * found = searchGlobalScope(methodCall -> data.value.string_value);
        struct ASTNode * expList = methodCall -> children[0];
        struct ASTNode * exp = expList -> children[0];
        struct ASTNode * expTail = expList -> children[1];

        // Create the instructions for all argument expressions
        if (found -> num_args > 0) {
            while (exp) {
                genExp(exp);
                exp = expTail -> children[0];
                if (exp) expTail = expTail -> children[1];                
            }
        }

        // Create the instruction for loading the argument registers
        for (int i = 0; i < instructionHead -> num_children; i++) {
            struct InstructionEntry * arg = instructionHead -> children[i];
            char instruction[20];
            sprintf(instruction, "ldr r%d, $t%d\n", i, arg -> temp_id);
            addToInstructionEntry(instruction);
        }

        // Create the instruction for branching terms
        char instruction[20];
        sprintf(instruction, "bl %s\n", methodCall -> data.value.string_value);
        addToInstructionEntry(instruction);
        
        // Create the instruction for loading r0 into a temp variable
        sprintf(instruction, "str r0, $t%d\n", tempCount);
        addToInstructionEntry(instruction);

        // Set the return symbolic register
        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> temp_id = tempCount;
        instructionHead -> offset = offset;
        offset += 4;
        tempCount++;

        exitInstructionScope();
    }
}

// Generate 3AC for expression declaration
void genExpDecl(struct ASTNode * expDecl) {
    if (expDecl -> node_type != NODETYPE_NULLABLE) {
        genExp(expDecl -> children[0]);
    }
}

// Generate 3AC for expression tree
void genExp(struct ASTNode * exp) {
    enum NodeType expType = exp -> node_type;
    if (expType == NODETYPE_ADDOP) {
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        createInstructionScope(exp, head);
        
        // Incorporate the nested expression instructions into the current instruction scope
        genExp(nestedExp);
        genTerm(term);
        
        // Define the arguments of the child scopes
        int arg1 = instructionHead -> children[0] -> temp_id;
        int arg2 = instructionHead -> children[1] -> temp_id;

        // Create the instruction for the expression operation
        char instruction[20];
        sprintf(instruction, "add $t%d, $t%d, $t%d\n", tempCount, arg1, arg2);
        addToInstructionEntry(instruction);
        
        // Provide the metadata for later instruction parsing
        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> temp_id = tempCount;
        instructionHead -> offset = offset;
        offset += 4;
        tempCount++;

        exitInstructionScope();
    } else if (expType == NODETYPE_SUBOP) {
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        createInstructionScope(exp, head);
        
        // Incorporate the nested expression instructions into the current instruction scope
        genExp(nestedExp);
        genTerm(term);
        
        // Define the arguments of the child scopes
        int arg1 = instructionHead -> children[0] -> temp_id;
        int arg2 = instructionHead -> children[1] -> temp_id;

        // Create the instruction for the expression operation
        char instruction[20];
        sprintf(instruction, "sub $t%d, $t%d, $t%d\n", tempCount, arg1, arg2);
        addToInstructionEntry(instruction);
        
        // Provide the metadata for later instruction parsing
        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> temp_id = tempCount;
        instructionHead -> offset = offset;
        offset += 4;
        tempCount++;

        exitInstructionScope(); 
    } else if (expType == NODETYPE_TERM) {
        genTerm(exp -> children[0]);
    }
}

void genTerm(struct ASTNode * term) {
    enum NodeType termType = term -> node_type;
    if (termType == NODETYPE_MULOP) {
        struct ASTNode * nestedTerm = term -> children[0];
        struct ASTNode * factor = term -> children[1];
        createInstructionScope(term, head);
        
        // Incorporate the nested expression instructions into the current instruction scope
        genTerm(nestedTerm);
        genFactor(factor);
        
        // Define the arguments of the child scopes
        int arg1 = instructionHead -> children[0] -> temp_id;
        int arg2 = instructionHead -> children[1] -> temp_id;

        // Create the instruction for the expression operation
        char instruction[20];
        sprintf(instruction, "mul $t%d, $t%d, $t%d\n", tempCount, arg1, arg2);
        addToInstructionEntry(instruction);
        
        // Provide the metadata for later instruction parsing
        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> temp_id = tempCount;
        instructionHead -> offset = offset;
        offset += 4;
        tempCount++;

        exitInstructionScope(); 
    } else if (termType == NODETYPE_DIVOP) {
        struct ASTNode * nestedTerm = term -> children[0];
        struct ASTNode * factor = term -> children[1];
        createInstructionScope(term, head);
        
        // Incorporate the nested expression instructions into the current instruction scope
        genTerm(nestedTerm);
        genFactor(factor);
        
        // Define the arguments of the child scopes
        int arg1 = instructionHead -> children[0] -> temp_id;
        int arg2 = instructionHead -> children[1] -> temp_id;

        // Create the instruction for the expression operation
        char instruction[20];
        sprintf(instruction, "sdiv $t%d, $t%d, $t%d\n", tempCount, arg1, arg2);
        addToInstructionEntry(instruction);
        
        // Provide the metadata for later instruction parsing
        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> temp_id = tempCount;
        instructionHead -> offset = offset;
        offset += 4;
        tempCount++;

        exitInstructionScope(); 
    } else if (termType == NODETYPE_FACTOR) {
        genFactor(term -> children[0]);
    }
}

// make sure to use the offsets stored in the node value as reference for varDecl, and method calls

void genFactor(struct ASTNode * factor) {
    enum NodeType factorType = factor -> node_type;
    if (factorType == NODETYPE_LITERAL) {
        createInstructionScope(factor, head);

        // Create the instruction for temporary literal
        char instruction[20];
        sprintf(instruction, "ldr $t%d, #%d\n", tempCount, factor -> data.value.int_value);
        addToInstructionEntry(instruction);  

        // Provide metadata for later instruction parsing          
        instructionHead -> temp_id = tempCount;
        instructionHead -> response_type = RESPONSETYPE_LITERAL; // change if global variable
        tempCount++;

        exitInstructionScope();
    } else if (factorType == NODETYPE_LEFTVALUE) {
        struct ASTNode * leftValue = factor -> children[0];

        if (leftValue -> node_type == NODETYPE_LEFTVALUE) {
            struct SymbolTableEntry * foundEntry = searchGlobalScope(leftValue -> data.value.string_value);
            createInstructionScope(factor, head);

            // Create the instruction for the temporary variable reference
            char instruction[40];
            sprintf(instruction, "mov $t%d, %s\n", tempCount, leftValue -> data.value.string_value); // replace with offsets assigned in local var prescreen
            addToInstructionEntry(instruction);   

            // Provide the metadata for later instruction parsing
            instructionHead -> temp_id = tempCount;
            instructionHead -> id = leftValue -> data.value.string_value;
            if (foundEntry -> var_type == VARTYPE_LOCAL || foundEntry -> var_type == VARTYPE_ARG) instructionHead -> response_type = RESPONSETYPE_LOCAL;
            else if (foundEntry -> var_type == VARTYPE_GLOBAL) instructionHead -> response_type = RESPONSETYPE_GLOBAL;
            tempCount++;

            exitInstructionScope();
        } else {
            struct ASTNode * index = leftValue -> children[0];
            struct SymbolTableEntry * foundEntry = searchGlobalScope(leftValue -> data.value.string_value);

            createInstructionScope(factor, head);
            
            genExp(index -> children[0]);

            // Create the instruction for the temporary variable reference
            char instruction[40];
            sprintf(instruction, "mov $t%d, %s\n", tempCount, leftValue -> data.value.string_value); // replace with offsets assigned in local var prescreen
            addToInstructionEntry(instruction);   

            // Provide the metadata for later instruction parsing
            instructionHead -> temp_id = tempCount;
            instructionHead -> id = leftValue -> data.value.string_value;
            instructionHead -> response_type = RESPONSETYPE_TEMP;
            instructionHead -> offset = offset;
            offset += 4;
            tempCount++;

            exitInstructionScope();
        }
    } else if (factorType == NODETYPE_METHODCALL) {
        genMethodCall(factor -> children[0]);
    } else if (factorType == NODETYPE_EXP) {
        genExp(factor -> children[0]);
    } else if (factorType == NODETYPE_PLUSOP) {
        createInstructionScope(factor, head);

        genFactor(factor -> children[0]);

        // Create the instruction for the temporary variable reference
        char instruction[40];
        sprintf(instruction, "ldr $t%d, +$%d\n", tempCount, instructionHead -> children[0] -> temp_id); // replace with offsets assigned in local var prescreen
        addToInstructionEntry(instruction);   

        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> temp_id = tempCount;
        instructionHead -> offset = offset;
        offset += 4;
        tempCount++;

        exitInstructionScope();
    } else if (factorType == NODETYPE_MINUSOP) {
        createInstructionScope(factor, head);

        genFactor(factor -> children[0]);

        // Create the instruction for the temporary variable reference
        char instruction[40];
        sprintf(instruction, "ldr $t%d, -$%d\n", tempCount, instructionHead -> children[0] -> temp_id); // replace with offsets assigned in local var prescreen
        addToInstructionEntry(instruction);   

        instructionHead -> response_type = RESPONSETYPE_TEMP;
        instructionHead -> temp_id = tempCount;
        instructionHead -> offset = offset;
        offset += 4;
        tempCount++;

        exitInstructionScope();
    }
}

/*
    Final run-through and eval functions
*/

void genMethodInit(struct ASTNode * node, char * id) {
    struct ScopeEntry * methodScope = findMethodScope(id, head);
    char branch[strlen(id) + 3];
    sprintf(branch, "%s:\n", id);

    instructionHead -> response_type = RESPONSETYPE_METHOD;
    instructionHead -> id = id;

    createInstructionScope(node, methodScope); // create a config instruction scope
    addToInstructionEntry(branch);
    addToInstructionEntry("push {lr}\n"); 

    // Load arguments from the registers (for non-main methods)
    struct SymbolTableEntry * foundMethod = searchGlobalScope(id);
    if (strcmp(id, "main") != 0) {
        for (int i = 0; i < foundMethod -> num_args; i++) {
            // Search for the argumentw within the method and adjust the scope
            head = methodScope;
            struct SymbolTableEntry * foundArg = searchLocalScope(foundMethod -> args[i] -> id);
            foundArg -> offset = offset;
            offset += 4;

            // Create the instruction
            char instruction[40];
            sprintf(instruction, "str r0, %s\n", foundMethod -> args[i] -> id); // replace with offsets assigned in local var prescreen
            addToInstructionEntry(instruction);   
        }
    }

    head = methodScope -> children[0]; // navigate to the method local scope for symbol table context
    genLocalVars(head);
    exitInstructionScope(); // exit the config instruction scope
 }

void genMethodEnd(struct ASTNode * node, char * id) {
    createInstructionScope(node, NULL); // method ending config instruction scope
    addToInstructionEntry("pop {pc}\n\n");

    // Standardize the total offsets used for later use
    struct SymbolTableEntry * foundMethod = searchGlobalScope(id);
    foundMethod -> offset = offset;
    offset = 0;

    exitInstructionScope(); // exit method ending config instruction scope
    exitInstructionScope(); // exit method instruction scope
    exitScope(); // exit local scope
    exitScope(); // exit method scope
}

// Apply offsets to local variables
void genLocalVars(struct ScopeEntry * scope) {
    if (scope == NULL) return;

    // Apply offset to all local variables
    for (int i = 0; i < scope -> num_entries; i++) {
        scope -> symbol_table[i] -> offset = offset;
        offset += 4;
    }
    
    // Check remaining scopes
    for (int i = 0; i < scope -> num_children; i++) {
        genLocalVars(scope -> children[i]);
    }
}

// Generate unoptimized ARM assembly from 3AC
void genTraversal(struct InstructionEntry * parent, struct InstructionEntry * curr) {
    for (int i = curr -> num_children - 1; i >= 0; i--) genTraversal(curr, curr -> children[i]);

    // If the scope is the root, just return
    if (parent == NULL) return;

    // Insert instructions to children as parent (inserting offset information for allocating stack variables)
    if (curr -> response_type == RESPONSETYPE_METHOD) {
        struct SymbolTableEntry * foundMethod = searchGlobalScope(curr -> id);
        struct InstructionEntry * config1 = curr -> children[0];
        struct InstructionEntry * config2 = curr -> children[curr -> num_children - 1];

        if (strcmp(curr -> id, "main") != 0) {
            // Insert allocation after pushing return reference
            char instruction[50];
            sprintf(instruction, "sub sp, sp, #%d\n", foundMethod -> offset);
            insertInstruction(curr, createInstruction(instruction), 2);
            memset(instruction, 0, strlen(instruction));

            for (int i = 0; i < foundMethod -> num_args; i++) {
                sprintf(instruction, "str r%d, [sp, #%d]\n", i, 4 * i);
                curr -> instructions[i + 3] = createInstruction(instruction);
                memset(instruction, 0, strlen(instruction));
            }

            // Insert deallocation at the last config
            sprintf(instruction, "add sp, sp, #%d\n", foundMethod -> offset);
            insertInstruction(curr, createInstruction(instruction), curr -> num_instructions - 1);
        } else {
            // Insert allocation after pushing return reference
            char instruction[100];
            sprintf(instruction, "mov r3, #4\n");
            insertInstruction(curr, createInstruction(instruction), 2);
            memset(instruction, 0, strlen(instruction));

            sprintf(instruction, "mul r2, r0, r3\nadd r2, r2, #%d\nsub sp, sp, r2\n", foundMethod -> offset + 4);
            insertInstruction(curr, createInstruction(instruction), 3);
            memset(instruction, 0, strlen(instruction));

            sprintf(instruction, "str r0, [sp, #%d]\nstr r1, [sp, #%d]\n", foundMethod -> offset, foundMethod -> offset + 4);
            insertInstruction(curr, createInstruction(instruction), 4);
            memset(instruction, 0, strlen(instruction));

            // Insert deallocation at the last config
            sprintf(instruction, "ldr r0, [sp, #%d]\nmov r1, #4\nmul r2, r0, r1\nadd r2, r2, #%d\nadd sp, sp, r2\n", foundMethod -> offset, foundMethod -> offset + 4);
            insertInstruction(curr, createInstruction(instruction), curr -> num_instructions - 1);        
        }
    }

    // Grab the sum of the child instruction entries to exclude re-evaluation
    int childInstructions = 0;
    for (int i = 0; i < curr -> num_children; i++) childInstructions += curr -> children[i] -> num_instructions;

    int iterator = 0;
    int original_length = curr -> num_instructions;

    // Handle all post-processing for the 3AC instructions
    for (int i = 0; i < original_length; i++) {
        if (i >= childInstructions) {
            if (curr -> response_type == RESPONSETYPE_LITERAL) { // literal var reference
                curr -> num_instructions -= 1; // since we are not using anymore instructions here, simply return
            } else if (curr -> response_type == RESPONSETYPE_LOCAL) { // local var reference
                curr -> num_instructions -= 1; // since we are not using anymore instructions here, simply return
            } else if (curr -> response_type == RESPONSETYPE_GLOBAL) { // global var reference
                curr -> num_instructions -= 1; // since we are not using anymore instructions here, simply return
            } else if (curr -> response_type == RESPONSETYPE_TEMP) { // intermediary result (all operation handlers)
                if (curr -> node -> node_type == NODETYPE_ADDOP) {
                    struct InstructionEntry * arg1 = curr -> children[0];
                    struct InstructionEntry * arg2 = curr -> children[1];
                    char * instruction;

                    // Load argument literals and variable references
                    instruction = genLoadChildNode(arg1, arg1 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;

                    instruction = genLoadChildNode(arg2, arg2 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Insert general operation instruction
                    insertInstruction(parent, createInstruction("add r2, r0, r1\n"), iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Add storage operation instruction
                    char storeInstruction[40];
                    sprintf(storeInstruction, "str r2, [sp, #%d]\n", curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_SUBOP) {
                    struct InstructionEntry * arg1 = curr -> children[0];
                    struct InstructionEntry * arg2 = curr -> children[1];
                    char * instruction;

                    // Load argument literals and variable references
                    instruction = genLoadChildNode(arg1, arg1 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;
                    instruction = genLoadChildNode(arg2, arg2 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Insert general operation instruction
                    insertInstruction(parent, createInstruction("sub r2, r0, r1\n"), iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Add storage operation instruction
                    char storeInstruction[40];
                    sprintf(storeInstruction, "str r2, [sp, #%d]\n", curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_MULOP) {
                    struct InstructionEntry * arg1 = curr -> children[0];
                    struct InstructionEntry * arg2 = curr -> children[1];
                    char * instruction;

                    // Load argument literals and variable references
                    instruction = genLoadChildNode(arg1, arg1 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;
                    
                    instruction = genLoadChildNode(arg2, arg2 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Insert general operation instruction
                    insertInstruction(parent, createInstruction("mul r2, r0, r1\n"), iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Add storage operation instruction
                    char storeInstruction[40];
                    sprintf(storeInstruction, "str r2, [sp, #%d]\n", curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_DIVOP) {
                    struct InstructionEntry * arg1 = curr -> children[0];
                    struct InstructionEntry * arg2 = curr -> children[1];
                    char * instruction;

                    // Load argument literals and variable references
                    instruction = genLoadChildNode(arg1, arg1 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;
                    
                    instruction = genLoadChildNode(arg2, arg2 -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Insert general operation instruction
                    insertInstruction(parent, createInstruction("sdiv r2, r0, r1\n"), iterator);
                    iterator++;
                    curr -> num_instructions++;

                    // Add storage operation instruction
                    char storeInstruction[40];
                    sprintf(storeInstruction, "str r2, [sp, #%d]\n", curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_METHODCALL) {                    
                    // Iterate through children and reformat the register loads
                    for (int j = 0; j < curr -> num_children; j++) {
                        struct InstructionEntry * arg = curr -> children[j];
                        char * instruction = genLoadChildNode(arg, j);
                        insertInstruction(parent, instruction, iterator);
                        iterator++;
                        i++;
                    }

                    // Finally insert the original branch and link instruction
                    insertInstruction(parent, curr -> instructions[iterator], iterator);
                    iterator++;
                    i++;

                    // Add storage operation instruction
                    char storeInstruction[40];
                    sprintf(storeInstruction, "str r0, [sp, #%d]\n", curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_PRINT || curr -> node -> node_type == NODETYPE_PRINTLN) {
                    struct InstructionEntry * arg1 = curr -> children[0];
                    char * instruction;

                    // Insert the first instruction (unchanged)
                    insertInstruction(parent, curr -> instructions[iterator], iterator);
                    iterator++;
                    i++;

                    // Load argument literals and variable references
                    instruction = genLoadChildNode(arg1, 1);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    i++;

                    // Insert the third instruction (unchanged)
                    insertInstruction(parent, curr -> instructions[iterator], iterator);
                } else if (curr -> node -> node_type == NODETYPE_VARDECL) {
                    // Load the expression into register
                    char * instruction;
                    instruction = genLoadChildNode(curr -> children[0], curr -> children[0] -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;
                    
                    // Add storage operation instruction
                    head = curr -> scope;
                    struct SymbolTableEntry * foundVariable = searchGlobalScope(curr -> id);
                    char storeInstruction[40];
                    sprintf(storeInstruction, "str r0, [sp, #%d]\n", foundVariable -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_RETURN) {
                    char * instruction;
                    instruction = genLoadChildNode(curr -> children[0], curr -> children[0] -> num_child);
                    insertInstruction(parent, instruction, iterator);
                } else if (curr -> node -> node_type == NODETYPE_LEFTVALUE) {
                    head = curr -> scope;
                    struct SymbolTableEntry * found = searchGlobalScope(curr -> id);
                    struct ScopeEntry * foundScope = nearestMethodScope();
                    struct SymbolTableEntry * foundMethod = searchGlobalScope(foundScope -> id);
                    printf("Checking here\n");
                    
                    char * instruction;
                    instruction = genLoadChildNode(curr -> children[0], curr -> children[0] -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;

                    char storeInstruction[100];
                    sprintf(storeInstruction, "add r0, r0, #1\nmov r1, #4\nmul r2, r0, r1\nldr r0, [sp, #%d]\nldr r0, [r0, r2]\nstr r0, [sp, #%d]\n", foundMethod -> offset + 4, curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_PLUSOP) {
                    char * instruction;
                    instruction = genLoadChildNode(curr -> children[0], curr -> children[0] -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;
                    
                    char storeInstruction[100];
                    sprintf(storeInstruction, "rsbpl r0, r0, #0\nstr r0, [sp, #%d]\n", curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                } else if (curr -> node -> node_type == NODETYPE_MINUSOP) {
                    char * instruction;
                    instruction = genLoadChildNode(curr -> children[0], curr -> children[0] -> num_child);
                    insertInstruction(parent, instruction, iterator);
                    iterator++;
                    curr -> num_instructions++;
                    
                    char storeInstruction[100];
                    sprintf(storeInstruction, "neg r0, r0\nstr r0, [sp, #%d]\n", curr -> offset);
                    insertInstruction(parent, createInstruction(storeInstruction), iterator);
                }
            } else {
                insertInstruction(parent, curr -> instructions[iterator], iterator);
            }
        } else {
            insertInstruction(parent, curr -> instructions[iterator], iterator);
        }
        
        iterator++;
    }
}

char * genLoadChildNode(struct InstructionEntry * leaf, int reg) {
    char instruction[100];
    
    if (leaf -> response_type == RESPONSETYPE_LITERAL) {
        sprintf(instruction, "mov r%d, #%d @ literal declaration\n", reg, leaf -> node -> data.value.int_value); 
    } else if (leaf -> response_type == RESPONSETYPE_LOCAL) {
        head = leaf -> scope;
        struct SymbolTableEntry * found = searchGlobalScope(leaf -> id);
        sprintf(instruction, "ldr r%d, [sp, #%d] @ local reference\n", reg, found -> offset); 
    } else if (leaf -> response_type == RESPONSETYPE_GLOBAL) {
        struct SymbolTableEntry * found = searchGlobalScope(leaf -> id);
        if (found -> data_type == DATATYPE_INT) {
            sprintf(instruction, "ldr r%d, =%s @ global reference\nldr r%d, [r%d, #0]\n", reg, leaf -> id, reg, reg);    
        } else {
            sprintf(instruction, "ldr r%d, =%s @ global reference\n", reg, leaf -> id);    
        }
    } else {
        sprintf(instruction, "ldr r%d, [sp, #%d] @ temp reference\n", reg, leaf -> offset);
    } 
    
    return createInstruction(instruction);
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
    child -> response_type = RESPONSETYPE_NULLABLE;
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