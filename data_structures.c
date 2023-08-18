// stack implementation in C NOT C++

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// implement a stack of variable length using a linked list
// each node in the linked list will be a stack element
// the stack will be a pointer to the top of the stack
// the stack will be a pointer to the bottom of the stack  
// the stack will have a size variable to keep track of the number of elements in the stack

// define a stack element
typedef struct stack_element {
    int value;
    struct stack_element *next;
} stack_element;





