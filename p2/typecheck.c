#include "typecheck.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int num_errors = 0;

struct ScopeEntry * head = NULL;

static void reportTypeViolation(int line_number) {
    num_errors += 1;
    fprintf(stderr, "Type violation in line %d\n", line_number);
}

/*
    All root typechecking
*/

// Begin type checking from root nonterminal
void checkProgram(struct ASTNode* program) {
    createScope(SCOPETYPE_GLOBAL);
    checkMain(program->children[program->num_children-1]);
}

// Check the main nonterminal 
void checkMain(struct ASTNode* mainClass) {
    char * argName = mainClass -> data.value.string_value;
    // May separate main function from class so ID is properly reflected
    
    // Create method forward references (including main)
    createMethodForwardReferences(mainClass->children[1]);
    struct SymbolTableEntry * mainMethodEntry = addToSymbolTable("main", ENTRYTYPE_METHOD, DATATYPE_UNDEFINED, 0);
    mainMethodEntry -> args[0] = createArgument(argName, DATATYPE_STR, 1);
    mainMethodEntry -> num_args = 1;

    // Check static variable and method declaration
    checkStaticVarDeclList(mainClass->children[0]);
    checkStaticMethodDeclList(mainClass->children[1]);

    // Change of scope before evaluating the main function, and inclusion of argument
    createScope(SCOPETYPE_METHOD);
    addToSymbolTable(mainMethodEntry-> args[0] -> id, ENTRYTYPE_VAR, mainMethodEntry-> args[0] -> data_type, 1);
    createScope(SCOPETYPE_LOCAL);

    // Check the statements of the main function
    checkStatementList(mainClass->children[2]);
    exitScope();
}

/*
    All variable declaration typechecking
*/

// Check the available static var decl lists (nullable)
void checkStaticVarDeclList(struct ASTNode* staticVarDeclList) {
    enum NodeType staticVarDeclListType = staticVarDeclList -> node_type;
    if (staticVarDeclListType == NODETYPE_NULLABLE) return;

    struct ASTNode * nextStaticVarDeclList = staticVarDeclList -> children[0];
    struct ASTNode * staticVarDecl = staticVarDeclList -> children[1];

    checkStaticVarDeclList(nextStaticVarDeclList);
    checkStaticVarDecl(staticVarDecl);
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

/*
    All expression-based typechecking
*/

// Check expression declaration for a given variable declaration (nullable)
void checkExpDecl(struct ASTNode* varDecl, struct ASTNode* parent, struct ASTNode* expDecl) {
    struct ASTNode * type = varDecl -> children[0];
    enum NodeType expDeclType = expDecl -> node_type;
    char * id = parent -> data.value.string_value;

    if (expDeclType != NODETYPE_NULLABLE) {
        struct ASTNode * exp = expDecl -> children[0];
        checkExp(exp);

        struct SymbolTableEntry * foundEntry = searchMethodScope(id);

        // If the variable already exists in the method scope, report an error
        if (foundEntry && (foundEntry -> data_type != type -> data.type || foundEntry -> num_indices != type -> data.num_indices)) {
            printf("Faulty variable declaration (already exists of different type)\n");
            reportTypeViolation(varDecl -> data.line_no);
            foundEntry -> data_type = DATATYPE_UNDEFINED;
        } else if (foundEntry) {
            printf("Faulty variable declaration (already exists)\n");
            reportTypeViolation(varDecl -> data.line_no);
        }

        // If there is a typing mismatch, report the error
        if ((exp -> data.type != type -> data.type || exp -> data.num_indices != type -> data.num_indices) &&
            !(exp -> data.type == DATATYPE_UNDEFINED || (foundEntry && foundEntry -> data_type == DATATYPE_UNDEFINED))) {
            printf("Variable declaration type mismatch\n");
            reportTypeViolation(varDecl -> data.line_no);
        }

        // If there is no error, add the variable to the symbol table
        if (!foundEntry) {
            addToSymbolTable(id, ENTRYTYPE_VAR, type -> data.type, type -> data.num_indices);
        }
    } else {
        struct SymbolTableEntry * foundEntry = searchMethodScope(id);

        // If the variable already exists in the method scope, report an error
        if (foundEntry && (foundEntry -> data_type != type -> data.type || foundEntry -> num_indices != type -> data.num_indices)) {
            printf("Faulty variable declaration (already exists of different type)\n");
            reportTypeViolation(varDecl -> data.line_no);
            foundEntry -> data_type = DATATYPE_UNDEFINED;
        } else if (foundEntry) {
            printf("Faulty variable declaration (already exists)\n");
            reportTypeViolation(varDecl -> data.line_no);
        } else {
            addToSymbolTable(id, ENTRYTYPE_VAR, type -> data.type, type -> data.num_indices);
        }
    }
}

// Check the given expression
void checkExp(struct ASTNode* exp) {
    enum NodeType expType = exp -> node_type;
    if (expType == NODETYPE_ADDOP) { // Check the add operation
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        checkExp(nestedExp);
        checkTerm(term);
        if (nestedExp -> data.type == DATATYPE_UNDEFINED || term -> data.type == DATATYPE_UNDEFINED) {
            exp -> data.type = DATATYPE_UNDEFINED;
        } else if (nestedExp -> data.type == DATATYPE_INT && term -> data.type == DATATYPE_INT &&
            nestedExp -> data.num_indices == 0 && term -> data.num_indices == 0) {
            exp -> data.type = DATATYPE_INT;
        } else if (nestedExp -> data.type == DATATYPE_STR && term -> data.type == DATATYPE_STR && 
            nestedExp -> data.num_indices == 0 && term -> data.num_indices == 0) {
            exp -> data.type = DATATYPE_STR;
        } else {
            printf("Faulty add/concat operation\n");
            reportTypeViolation(exp -> data.line_no);
            exp -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (expType == NODETYPE_TERMOP) { // Check the remaining expression and term operations
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        checkExp(nestedExp);
        checkTerm(term);
        if (nestedExp -> data.type == DATATYPE_UNDEFINED || term -> data.type == DATATYPE_UNDEFINED) {
            exp -> data.type = DATATYPE_UNDEFINED;
        } else if (nestedExp -> data.type == DATATYPE_INT && term -> data.type == DATATYPE_INT &&
            nestedExp -> data.num_indices == 0 && term -> data.num_indices == 0) {
            exp -> data.type = DATATYPE_INT;
        } else {
            printf("Faulty minus operation\n");
            reportTypeViolation(exp -> data.line_no);
            exp -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (expType == NODETYPE_COMPOP) { // Check the comparison operations
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        checkExp(nestedExp);
        checkTerm(term);
        if (term -> data.type == DATATYPE_UNDEFINED) {
            exp -> data.type = DATATYPE_UNDEFINED;
        } else if (term -> data.type == nestedExp -> data.type && term -> data.num_indices == 0 && nestedExp -> data.num_indices == 0) {
            exp -> data.type = DATATYPE_BOOLEAN;
        } else {
            printf("Faulty comparison operation\n");
            reportTypeViolation(exp -> data.line_no);
            exp -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (expType == NODETYPE_BINOP) { // Check the binary operations
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        checkExp(nestedExp);
        checkTerm(term);
        if (nestedExp -> data.type == DATATYPE_UNDEFINED || term -> data.type == DATATYPE_UNDEFINED) {
            exp -> data.type = DATATYPE_UNDEFINED;
        } else if (nestedExp -> data.type == DATATYPE_BOOLEAN && term -> data.type == DATATYPE_BOOLEAN &&
            nestedExp -> data.num_indices == 0 && term -> data.num_indices == 0) {
            exp -> data.type = DATATYPE_BOOLEAN;
        } else {
            printf("Faulty binary operation\n");
            reportTypeViolation(exp -> data.line_no);
            exp -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (expType == NODETYPE_EQOP) {
        struct ASTNode * nestedExp = exp -> children[0];
        struct ASTNode * term = exp -> children[1];
        checkExp(nestedExp);
        checkTerm(term);
        if (nestedExp -> data.type == DATATYPE_UNDEFINED || term -> data.type == DATATYPE_UNDEFINED) {
            exp -> data.type = DATATYPE_UNDEFINED;
        } else if (nestedExp -> data.type == term -> data.type && nestedExp -> data.num_indices == term -> data.num_indices) {
            exp -> data.type = DATATYPE_BOOLEAN;
        } else {
            printf("Faulty equals comparison operation\n");
            reportTypeViolation(exp -> data.line_no);
            exp -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (expType == NODETYPE_TERM) { // Check the remaining term
        struct ASTNode * term = exp -> children[0];
        checkTerm(term);
        exp -> data.type = term -> data.type;
        exp -> data.num_indices = term -> data.num_indices;
    }
}

void checkTerm(struct ASTNode* term) {
    enum NodeType termType = term -> node_type;
    if (termType == NODETYPE_FACTOP) { // Check the term and factor operations
        struct ASTNode * nestedTerm = term -> children[0];
        struct ASTNode * factor = term -> children[1];
        checkTerm(nestedTerm);
        checkFactor(factor);
        if (nestedTerm -> data.type == DATATYPE_UNDEFINED || factor -> data.type == DATATYPE_UNDEFINED) {
            term -> data.type = DATATYPE_UNDEFINED;
        } else if (nestedTerm -> data.type == DATATYPE_INT && factor -> data.type == DATATYPE_INT &&
            nestedTerm -> data.num_indices == 0 && factor -> data.num_indices == 0) {
            term -> data.type = DATATYPE_INT;
        } else {
            printf("Faulty factor operation\n");
            reportTypeViolation(term -> data.line_no);
            term -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (termType == NODETYPE_FACTOR) { // Check the remaining factor
        struct ASTNode * factor = term -> children[0];
        checkFactor(factor);
        term -> data.type = factor -> data.type;
        term -> data.num_indices = factor -> data.num_indices;
    }
}

void checkFactor(struct ASTNode* factor) {
    enum NodeType factorType = factor -> node_type;
    if (factorType == NODETYPE_LITERAL) { // Ignore literal declarations
        return;
    } else if (factorType == NODETYPE_EXP) { // Check the wrapped expression
        struct ASTNode * exp = factor -> children[0];
        checkExp(exp);
        factor -> data.type = exp -> data.type;
        factor -> data.num_indices = exp -> data.num_indices;
    } else if (factorType == NODETYPE_LEFTVALUE) { // Check the left value
        struct ASTNode * leftValue = factor -> children[0];
        checkLeftValue(leftValue);
        factor -> data.type = leftValue -> data.type;
        factor -> data.num_indices = leftValue -> data.num_indices;
    } else if (factorType == NODETYPE_LENGTH) { // Check the left value length operation
        struct ASTNode * leftValue = factor -> children[0];
        checkLeftValue(leftValue);
        if (leftValue -> data.type == DATATYPE_UNDEFINED) {
            factor -> data.type = DATATYPE_UNDEFINED;
        } else if (leftValue -> data.num_indices > 0) {
            factor -> data.type = DATATYPE_INT;
        } else {
            printf("Faulty length operation\n");
            reportTypeViolation(factor -> data.line_no);
            factor -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (factorType == NODETYPE_ADJOP) { // Check the adjustment operations
        struct ASTNode * nestedFactor = factor -> children[0];
        checkFactor(nestedFactor);
        if (nestedFactor -> data.type == DATATYPE_UNDEFINED) {
            factor -> data.type = DATATYPE_UNDEFINED;
        } else if (nestedFactor -> data.type == DATATYPE_INT && nestedFactor -> data.num_indices == 0) {
            factor -> data.type = DATATYPE_INT;
        } else {
            printf("Faulty adjustment operation\n");
            reportTypeViolation(factor -> data.line_no);
            factor -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (factorType == NODETYPE_NOT) { // Check the binary adjustment operations
        struct ASTNode * nestedFactor = factor -> children[0];
        checkFactor(nestedFactor);
        if (nestedFactor -> data.type == DATATYPE_UNDEFINED) {
            factor -> data.type = DATATYPE_UNDEFINED;
        } else if (nestedFactor -> data.type == DATATYPE_BOOLEAN && nestedFactor -> data.num_indices == 0) {
            factor -> data.type = DATATYPE_BOOLEAN;
        } else {
            printf("Faulty binary adjustment operation\n");
            reportTypeViolation(factor -> data.line_no);
            factor -> data.type = DATATYPE_UNDEFINED;
        }
    } else if (factorType == NODETYPE_METHODCALL) { // Check the method call
        struct ASTNode * methodCall = factor -> children[0];
        checkMethodCall(methodCall);
        factor -> data.type = methodCall -> data.type;
        factor -> data.num_indices = methodCall -> data.num_indices;
    } else if (factorType == NODETYPE_ARRAY) { // may consider moving this instruction/grammar
        struct ASTNode * primeType = factor -> children[0];
        struct ASTNode * index = factor -> children[1];
        int numIndices = checkIndex(index);
        factor -> data.type = primeType -> data.type;
        factor -> data.num_indices = numIndices;
    }
} 

/*
    All method-based typechecking
*/

// Check the formal_lists of each method and create a global entry for forward references (nullable)
void createMethodForwardReferences(struct ASTNode* staticMethodDeclList) {
    enum NodeType staticMethodDeclListType = staticMethodDeclList -> node_type;
    if (staticMethodDeclListType == NODETYPE_NULLABLE) return;
    
    struct ASTNode * nextStaticMethodDeclList = staticMethodDeclList -> children[0];
    struct ASTNode * staticMethodDecl = staticMethodDeclList -> children[1];

    createMethodForwardReferences(nextStaticMethodDeclList);
    createMethodForwardReference(staticMethodDecl);
}

// Create an individual method global entry for forward references
void createMethodForwardReference(struct ASTNode* staticMethodDecl) {
    struct ASTNode * type = staticMethodDecl -> children[0];
    struct ASTNode * formalList = staticMethodDecl -> children[1];
    char * id = staticMethodDecl -> data.value.string_value;
    enum DataType dataType = type -> data.type;

    // Check for duplicate method declarations
    struct SymbolTableEntry * foundEntry = searchGlobalScope(id);
    if (foundEntry) {
        printf("Faulty method declaration (already exists)\n");
        reportTypeViolation(formalList -> data.line_no);
        foundEntry -> data_type = DATATYPE_UNDEFINED;
    } else {
        // Create symbol table entry
        struct SymbolTableEntry * entry = addToSymbolTable(id, ENTRYTYPE_METHOD, dataType, 0);

        // Evaluate the formal list arguments
        if (formalList -> node_type != NODETYPE_NULLABLE) {
            struct ASTNode * arg = formalList -> children[0];
            struct ASTNode * argList = formalList -> children[1];

            // Navigate through arg_list adding arguments to entry
            while (arg) { 
                struct ASTNode * argType = arg -> children[0];
                entry -> args[entry -> num_args] = createArgument(arg -> data.value.string_value, argType -> data.type, arg -> data.num_indices);
                entry -> num_args++;
                
                if (argList -> node_type == NODETYPE_NULLABLE) break;
                arg = argList -> children[0];
                argList = argList -> children[1];
            }
        }
    }
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

// Check a given method call
void checkMethodCall(struct ASTNode* methodCall) {
    enum NodeType methodCallType = methodCall -> node_type;
    if (methodCallType == NODETYPE_METHODCALL) { // Check all traditional method calls
        char * methodName = methodCall -> data.value.string_value;
        struct SymbolTableEntry * entry = searchGlobalScope(methodName);
        
        // If method does not exist, return error
        if (!entry || entry -> type != ENTRYTYPE_METHOD) {
            printf("Faulty method call (does not exist)\n");
            reportTypeViolation(methodCall -> data.line_no);
            methodCall -> data.type = DATATYPE_UNDEFINED;
        }

        // If method entry is undefined, pass value as undefined, otherwise evaluate arguments
        if (entry && entry -> data_type == DATATYPE_UNDEFINED) {
            methodCall -> data.type = DATATYPE_UNDEFINED;
        } else if (entry) {
            struct ASTNode * expList = methodCall -> children[0];
            if (expList -> node_type == NODETYPE_NULLABLE && entry -> num_args > 0) {
                printf("Not enough arguments\n");
                reportTypeViolation(methodCall -> data.line_no);
            } else {
                struct ASTNode * exp = expList -> children[0];
                struct ASTNode * expTail = expList -> children[1];
                
                for (int i = 0; i < entry -> num_args; i++) {
                    if (!exp) {
                        printf("Not enough arguments\n");
                        reportTypeViolation(methodCall -> data.line_no);
                        break;
                    } else {
                        checkExp(exp);
                        if (exp -> data.type == DATATYPE_UNDEFINED) {
                            break;
                        } else if (exp -> data.type != entry -> args[i] -> data_type || exp -> data.num_indices != entry -> args[i] -> num_indices) {
                            printf("Invalid argument type\n");
                            reportTypeViolation(methodCall -> data.line_no);
                            break;
                        }
                    }

                    if (expTail -> node_type == NODETYPE_NULLABLE) {
                        exp = NULL;
                    } else {
                        exp = expTail -> children[0];
                        expTail = expTail -> children[1];
                        if (i == entry -> num_args - 1) {
                            printf("Too many arguments\n");
                            reportTypeViolation(methodCall -> data.line_no);
                            break;
                        }
                    }
                }
            }
            
            methodCall -> data.type = entry -> data_type;
            methodCall -> data.num_indices = entry -> num_indices;
        }
    } else if (methodCallType == NODETYPE_PARSEINT) { // Check for parseInt method calls
        struct ASTNode * exp = methodCall -> children[0];
        if (exp -> data.type == DATATYPE_STR) {
            methodCall -> data.type = DATATYPE_INT;
        } else {
            printf("Faulty parse int (invalid typing)\n");
            reportTypeViolation(methodCall -> data.line_no);
            methodCall -> data.type = DATATYPE_UNDEFINED;
        }
    }
}

// Check the given static method decl
void checkStaticMethodDecl(struct ASTNode* staticMethodDecl) {
    createScope(SCOPETYPE_METHOD);
    struct ASTNode * formalList = staticMethodDecl -> children[1];
    struct ASTNode * statementList = staticMethodDecl -> children[2];

    /*
        FIX THE ARG LIST HERE TO ACCOMODATE FOR METHOD OVERLOADING
    */

    // Change the scope and add in arguments to the method scope
    createScope(SCOPETYPE_METHOD);    
    struct SymbolTableEntry * methodEntry = searchGlobalScope(staticMethodDecl -> data.value.string_value);
    for (int i = 0; i < methodEntry -> num_args; i++) {
        struct SymbolTableEntry * argEntry = searchLocalScope(methodEntry -> args[i] -> id);
        if (argEntry) {
            printf("Duplicate arguments\n");
            reportTypeViolation(formalList -> data.line_no);
            argEntry -> data_type = DATATYPE_UNDEFINED;
        } else {
            addToSymbolTable(methodEntry -> args[i] -> id, ENTRYTYPE_VAR, methodEntry -> args[i] -> data_type, methodEntry -> args[i] -> num_indices);
        }
    }
    createScope(SCOPETYPE_LOCAL);
    // TODO (check function symbol table entry and statementlist [maybe return value typing as well])

    checkStatementList(statementList);
    exitScope();
    exitScope();
}

/*
    All statement-based typechecking
*/

int checkIndex(struct ASTNode* index) {
    enum NodeType indexType = index -> node_type;
    int num_indices = 1;

    if (indexType == NODETYPE_INDEXLIST) {
        struct ASTNode * newIndex = index -> children[0];
        struct ASTNode * exp = index -> children[1];
        
        num_indices += checkIndex(newIndex);
        checkExp(exp);
        
        if (exp -> data.type != DATATYPE_INT || exp -> data.num_indices > 0) {
            printf("Faulty index list\n");
            reportTypeViolation(exp -> data.line_no);
        }
    } else if (indexType == NODETYPE_INDEX) {
        struct ASTNode * exp = index -> children[0];
        
        checkExp(exp);

        if (exp -> data.type != DATATYPE_INT || exp -> data.num_indices > 0) {
            printf("Faulty index\n");
            reportTypeViolation(exp -> data.line_no);
        }
    }

    return num_indices;
}

void checkLeftValue(struct ASTNode* leftValue) {
    enum NodeType leftValueType = leftValue -> node_type;

    if (leftValueType == NODETYPE_LEFTVALUE) {
        char * leftValueName = leftValue -> data.value.string_value;
        struct SymbolTableEntry * foundEntry = searchGlobalScope(leftValueName);
        
        if (!foundEntry || foundEntry -> type != ENTRYTYPE_VAR) {
            printf("Variable does not exist %s\n", leftValueName);
            reportTypeViolation(leftValue -> data.line_no);
            leftValue -> data.type = DATATYPE_UNDEFINED;
        } else {
            leftValue -> data.type = foundEntry -> data_type;
            leftValue -> data.num_indices = foundEntry -> num_indices;
        }
    } else if (leftValueType == NODETYPE_LEFTVALUEINDEX) {
        char * leftValueName = leftValue -> data.value.string_value;
        struct ASTNode * index = leftValue -> children[0];
        struct SymbolTableEntry * foundEntry = searchGlobalScope(leftValueName);

        // Handle multiple indices and check the number of indices referenced
        int changeOfIndices = checkIndex(index);
        if (changeOfIndices > foundEntry -> num_indices) {
            printf("Variable does not support elicited indices\n");
            reportTypeViolation(leftValue -> data.line_no);
            //leftValue -> data.type = DATATYPE_UNDEFINED;
        }

        // If variable doesnt exist in global scope return type error
        if (!foundEntry || foundEntry -> type != ENTRYTYPE_VAR) {
            printf("Faulty left value\n");
            reportTypeViolation(leftValue -> data.line_no);
            leftValue -> data.type = DATATYPE_UNDEFINED;
        } else {
            leftValue -> data.type = foundEntry -> data_type;
            leftValue -> data.num_indices = foundEntry -> num_indices - changeOfIndices;
        }
    }
}

// Check the available statement lists (nullable)
void checkStatementList(struct ASTNode* statementList) {
    enum NodeType statementListType = statementList -> node_type;
    if (statementListType != NODETYPE_NULLABLE) {
        struct ASTNode * nextStatementList = statementList -> children[0];
        struct ASTNode * statement = statementList -> children[1];

        checkStatementList(nextStatementList);
        checkStatement(statement);
    }
}

// TODO add return value typechecking
// TODO make sure that multiple methods are not allowed

// TODO finish the rest of the statement typechecking
// TODO make sure that rules are not reporting multiple repeat type violations
// TODO check the arguments for the method calls
// TODO add in num_indices checking for all of the type explicit rules
// TODO change the forward references to check for name clashing and set typings to undefined

// Check the given statement
void checkStatement(struct ASTNode* statement){
    enum NodeType statementType = statement -> node_type;
    if (statementType == NODETYPE_PRINT || statementType == NODETYPE_PRINTLN) {
        struct ASTNode * exp = statement -> children[0];
        checkExp(exp);
        if (exp -> data.num_indices > 0 && !exp -> data.type == DATATYPE_UNDEFINED) {
            printf("Invalid parameters for print statement\n");
            reportTypeViolation(statement -> data.line_no);
        }
    } else if (statementType == NODETYPE_VARDECL) {
        struct ASTNode * varDecl = statement -> children[0];
        checkVarDecl(varDecl);
    } else if (statementType == NODETYPE_STATEMENTLIST) {
        struct ASTNode * statementList = statement -> children[0];
        checkStatementList(statementList);
    } else if (statementType == NODETYPE_IFELSE) {
        struct ASTNode * exp = statement -> children[0];
        struct ASTNode * firstArgStatement = statement -> children[1];
        struct ASTNode * secArgStatement = statement -> children[2];
        checkExp(exp);
        if (exp -> data.type != DATATYPE_BOOLEAN || exp -> data.num_indices > 0) {
            printf("Invalid if conditional\n");
            reportTypeViolation(statement -> data.line_no);
        }
        createScope(SCOPETYPE_LOCAL);
        checkStatement(firstArgStatement);
        exitScope();
        createScope(SCOPETYPE_LOCAL);
        checkStatement(secArgStatement);
        exitScope();
    } else if (statementType == NODETYPE_WHILE) {
        struct ASTNode * exp = statement -> children[0];
        struct ASTNode * argStatement = statement -> children[1];
        checkExp(exp);
        if (exp -> data.type != DATATYPE_BOOLEAN || exp -> data.num_indices > 0) {
            printf("Invalid while conditional\n");
            reportTypeViolation(statement -> data.line_no);
        }
        createScope(SCOPETYPE_LOCAL);
        checkStatement(argStatement);
        exitScope();
    } else if (statementType == NODETYPE_REASSIGN) {
        struct ASTNode * leftValue = statement -> children[0];
        struct ASTNode * exp = statement -> children[1];
        checkLeftValue(leftValue);
        checkExp(exp);
        if ((leftValue -> data.type != exp -> data.type || leftValue -> data.num_indices != exp -> data.num_indices) &&
            (exp -> data.type != DATATYPE_UNDEFINED && leftValue -> data.type != DATATYPE_UNDEFINED)) {
            printf("Reassignment type mismatch\n");
            reportTypeViolation(statement -> data.line_no);
        }
    } else if (statementType == NODETYPE_RETURN) {
        struct ASTNode * exp = statement -> children[1];
        checkExp(exp);

        // add return value type checking here

    } else if (statementType == NODETYPE_METHODCALL) {
        struct ASTNode * methodCall = statement -> children[0];
        checkMethodCall(methodCall);
    }
}

/*
    All argument handler functions
*/

struct ArgEntry * createArgument(char * id, enum DataType data_type, int num_indices) {
    struct ArgEntry * entry = malloc(sizeof(struct ArgEntry));
    entry -> id = id;
    entry -> data_type = data_type;
    entry -> num_indices = num_indices;
    return entry;
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

struct SymbolTableEntry * addToSymbolTable(char * id, enum EntryType type, enum DataType data_type, int num_indices){
    if (head -> num_entries < MAX_TABLE_SIZE - 1) {
        struct SymbolTableEntry* entry = malloc(sizeof(struct SymbolTableEntry));
        entry -> id = id;
        entry -> type = type;
        entry -> data_type = data_type;
        entry -> num_args = 0;
        entry -> num_indices = num_indices;
        head -> symbol_table[head -> num_entries] = entry;
        head -> num_entries++;
        return entry;
    } else {
        return NULL;
    }
}