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

General explanation here

## Grammar

Explain grammars here

## Abstract Symbol Table

Explain the abstract symbol table and node generation

## Scope Reduction

Explain the scope reduction processes leading into the symbol table 

## Symbol Table

Explain the symbol table

## Other

Explain all other methodologies
