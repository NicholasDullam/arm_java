TODO: Fix the duplicate method handling
    redeclaration should make method undefined, and all calls should be undefined (not call another type error)
    make the second definition of the method result in the type error
    also check for the duplicate arguments by fixing the references to arguments for each static method declaration

    may need to change staticMethodDecl to accomodate for the argList outside of the forward references (since we still want to typecheck the overloaded method)

TODO: Fix the sorting of type violations

TODO: For the method handling, use the table entry "declarations" to handle error reporting at the proper stage

TODO: Fix undefined type of pseudo methods like .length, if statements and while loops, and methodcalls

TODO (DONE): Check the precedance and rules with '-' and '+' adjustments

TODO (DONE): Change the equals and nequals behavior for reference pointers (like arrays)

TODO: if duplicate args are the same type, dont make the undefined
TODO: if multiple method definitions exist of the same return type, dont make the type undefined
TOOD: fulfill return type checking

# Project 2 Overview

## Grammar

The grammar, while matching the expectations of the project guidelines, includes sub-nonterminals resulting from the derivation from extended BST, alongside adjustments for simplified semantics. Some of these new nonterminals include ```StaticVarDeclList```, ```VarDeclExpList```, ```StatementList```, ```StaticMethodDeclList```, ```Arg```, ```ArgList```, ```Term```, ```Factor```, ```ExpDecl```, ```ExpList```, and ```ExpTail```. Expressions of these new nonterminals, alongside expected nonterminals, can be found in ```parser.y```, with token definitions expressed in ```parser.l```.

## Abstract Symbol Table

To create the AST, as was demonstrated in class, I created a tree structure using ```ASTNode```, where each node would have it's corresponding child nodes, ```node_type```, used for distinction in type checking, alongside ```data``` which is home to the ```data_type``` and the unionized semantic values (i.e. ```value.string_value```, given the behavior of node typing being exclusive to a specific value). For each reduced nonterminal, a node is created, and each grammar rule that incorporates right-hand nonterminals creates a new node, and adds each nonterminal as a child from left to right. This structure enables to navigation of the arguments in order of priority when evaluating type semantics. When applying values to each node, ```data_type``` is directly implied; however, in some cases, as with the ```Type``` and ```PrimeType``` nonterminals, the ```data_type``` can be directly applied or derived from the right-hand nonterminal nodes (soon to be children) without an attached implicit value. Alongside the ```data_type```, to derive array types, another field, ```num_indices```, representing the depth of the array. Finally, for recorded the line number with which an error should be reported, each node exhibits a ```line_no``` that is expressed at node creation, alongside ```num_children```. Breakdowns of the ```ASTNode``` struct and it's accompanied enumerators can be found in ```node.h```, with function assignments in ```node.c```.

## Symbol Table

Incorporating the symbol table involved the creation of ```SymbolTableEntry```, which ellicits the ```id```, ```type```, being the ```EntryType```, the ```data_type```, being the ```DataType```, alongside ```num_indices```, ```num_args```, and ```args```, which is an array of type struct ```ArgEntry```. Arguments, which may or may not be populated for a given method, contain similar identifiable information for a given argument, including the ```data_type```, ```num_indices```, and ```id```. A symbol table is used to represent the context of both method and variable declarations for the program, given the aforementioned ```type``` variable for distinguishing variables on lookup; however, rather than having a global symbol table, symbol tables are divided based on the scope in which the variable or method precides in. This implies that each scope has it's own symbol table, and any request to create a variable or method will add to the symbol table of the current scope head (this behavior will be touched on next in the scope reduction). All of the declarations and definitions involving the symbol table can be found in ```typecheck.h``` and ```typecheck.c```.

## Scope Reduction

Alongside the ```ASTNode``` struct for managing the abstract symbol table, to apply scope variable, method, and argument declarations, I created a ```ScopeEntry``` struct. For each hypothetical scope, we'd create an accompanied symbol table, allowing variable and method accessibility based on the level of the scope search. ```ScopeEntry```'s can be divided into three types, including ```DATATYPE_GLOBAL```, ```DATATYPE_METHOD```, and ```DATATYPE_LOCAL```. The global data type serves as the root scope, with the method scope, as one could assume, bounding methods, serves as a bounding scope for the accessibility and redeclaration of method arguments (an example of this behavior can be seen in the ```searchMethodScope``` function, where redeclarations evaluate symbols up until the method scope, while ```LeftValue``` reads and reassignments are evaluated under the global scope). For handling scope navigation, each ```ScopeEntry``` has a series of ```ScopeEntry``` children and a ```ScopeEntry``` parent node, of which ```exitScope``` moves the head to the parent node when available, and ```createScope``` moves the head to the newly created scope, adding a child entry to the previous head. All of the declarations and definitions involving the scope reduction can be found in ```typecheck.h``` and ```typecheck.c```.

## Type Checking

For the purposes of type checking, I follow through with a generally traditional traversal of the aforementioned AST, following depth-first through the accompanied nodes and grammars (with a few notable exceptions, primarily in the realm of handling method forward references). I divided all necessary grammars into individual functions for checking, acting to recursively evaluate the type and correctness of a given branch of the AST, and redefining their ```ASTNode``` typing for use in the parent function. What should be noted is how baseline types are propagated, most notable with the ```PrimeType```, and ```Type``` grammars. Both of these grammars propagate their typing outside of the evaluation of the AST, at node creation; this choice was made given it's simplicity and limited fundamental grammars. Grammars that incorporate right-hand nonterminals follow through by checking the child components first in their respective ordering, ensuring the proper reporting of type errors. Given each grammar rule's/node's ```node_type``` the grammar can be properly handled. One note given the behavior of the grammar is the handling of nullable fields, where typechecking should be ignored -- this is managed through the ```node_type```, where a reserved value of ```NODETYPE_NULLABLE``` is checked for each nullable grammar for respective handling. When evaluating variable and method declarations, alongside reassignments, using our aforementioned ```ScopeEntry``` and ```SymbolTableEntry```, we verify the existence of variables up to the method scope when declaring variables, and verify the existence of variables up to the global scope when reading/reassigning variables. If a variable is redeclared in the local scope, it's reassignment with prioritize the "closest" instance -- that's to say the variable that is closer to the scope head. When entering a function, a new scope is created for the method, of ```ENTRYTYPE_METHOD```, following by a declaration of each of it's arguments. After type checking and assignment for the arguments, a new local scope is created, of ```ENTRYTYPE_LOCAL```, enabling the redeclaration of method variables (as method scope ```SymbolTableEntry```'s are excluded in ```searchMethodScope```). For all cases where an expression, method, or variable are of ```DATATYPE_UNDEFINED```, further type errors are excluded (unless otherwise noted). All of the declarations and definitions involving type checking can be found in ```typecheck.h``` and ```typecheck.c```.

