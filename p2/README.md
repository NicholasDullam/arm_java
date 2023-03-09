TODO: Fix the duplicate method handling
    redeclaration should make method undefined, and all calls should be undefined (not call another type error)
    make the second definition of the method result in the type error
    also check for the duplicate arguments by fixing the references to arguments for each static method declaration

    may need to change staticMethodDecl to accomodate for the argList outside of the forward references (since we still want to typecheck the overloaded method)

TODO: Fix the sorting of type violations

TODO: For the method handling, use the table entry "declarations" to handle error reporting at the proper stage