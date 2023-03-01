#ifndef NODE_H
#define NODE_H
#define MAX_NUM_CHILDREN 3

#include <stdbool.h>

enum DataType { DATATYPE_UNDEFINED, DATATYPE_STR, DATATYPE_INT, DATATYPE_BOOLEAN };

// Returns the name of the given data type.
static inline const char *type_string(enum DataType t) {
    static const char *names[] = {"Undefined", "String", "Integer", "Boolean"};
    return names[t % 4];
}

struct SemanticData {
    enum DataType type;
    union value_t {
        char* string_value;
        int int_value;
        bool boolean_value;
    } value;
};

enum NodeType {
    NODETYPE_PROGRAM,
    NODETYPE_MAINCLASS,
    
    NODETYPE_VARDECL,
    NODETYPE_METHODCALL,
    NODETYPE_PRINT,
    NODETYPE_PRINTLN,
    
    NODETYPE_PRIMETYPE,
    NODETYPE_TYPE,
    NODETYPE_LEFTVALUE,
    NODETYPE_INDEX,
    NODETYPE_EXP,
    NODETYPE_EXPLIST,
    NODETYPE_EXPTAIL
};

struct ASTNode {
    struct ASTNode* children[MAX_NUM_CHILDREN];
    int num_children;
    
    enum NodeType node_type;
    struct SemanticData data;
};


// Creates a new node with 0 children on the heap using `malloc()`.
struct ASTNode* new_node(enum NodeType t);
// Adds the given children to the parent node. Returns -1 if the capacity is full.
int add_child(struct ASTNode* parent, struct ASTNode* child);

// Sets the data of the node to the given value and the corresponding type.

void set_string_value(struct ASTNode* node, char* s);
void set_int_value(struct ASTNode* node, int i);
void set_boolean_value(struct ASTNode* node, bool b);

#endif
