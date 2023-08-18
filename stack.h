// header file for stack class in C not C++

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// variable stack
typedef struct {
    int *contents;
    int top;
    int size;
} Stack;

// function prototypes
Stack* create_stack(int size);
void push(Stack *stack, int value); 
int pop(Stack *stack);
int peek(Stack *stack);
bool is_empty(const Stack *stack);
void print_stack(Stack *stack);
void free_stack(Stack *stack);
void stack_overflow();
void stack_underflow();

#endif



