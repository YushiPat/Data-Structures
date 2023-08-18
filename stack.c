// implementation of stack.h in C NOT C++

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// implement a stack of variable length using a linked list
// the structure is defined in stack.h
#include "stack.h"
#include <printf.h>
#include <assert.h>

// create a new stack
Stack* create_stack(int size) {
    Stack *stack = malloc(sizeof(Stack));
    stack->contents = malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

// push a value onto the stack and make sure address is valid
void push(Stack *stack, int value) {
    if (stack->top == stack->size - 1) {
        stack->size *= 2;
        stack->contents = realloc(stack->contents, sizeof(int) * stack->size);
    }
    stack->top++;
    stack->contents[stack->top] = value;
}

// pop a value off the stack and make sure address is valid
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    int value = stack->contents[stack->top];
    stack->top--;
    return value;
}

// peek at the top of the stack
int peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->contents[stack->top];
}

// check if stack is empty
bool is_empty(const Stack *stack) {
    return stack->top == -1;
}

// print the stack
void print_stack(Stack *stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->contents[i]);
    }
    printf("\n");
}

// free the stack
void free_stack(Stack *stack) {
    free(stack->contents);
    free(stack);
}

void stack_overflow(void) {
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
} 


void test_pop(){
    Stack *stack = create_stack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    assert(pop(stack) == 3);
    assert(pop(stack) == 2);
    assert(pop(stack) == 1);
    printf("test_pop passed\n");
    free_stack(stack);
}

void test_peek(){
    Stack *stack = create_stack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    assert(peek(stack) == 3);
    pop(stack);
    assert(peek(stack) == 2);
    printf("test_peek passed\n");
    free_stack(stack);
}

void test_is_empty(){
    Stack *stack = create_stack(3);
    assert(is_empty(stack));
    push(stack, 1);
    assert(!is_empty(stack));
    printf("test_is_empty passed\n");
    free_stack(stack);
}

void test_print_stack(){
    Stack *stack = create_stack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    print_stack(stack);
    printf("test_print_stack passed\n");
    free_stack(stack);
}

void test_free_stack(){
    Stack *stack = create_stack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    free_stack(stack);
    assert(stack->contents == NULL);
    printf("test_free_stack passed\n");
}

void test_stack_overflow(){
    Stack *stack = create_stack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    assert(stack->size == 6);
    printf("test_stack_overflow passed\n");
    free_stack(stack);
}

void test_stack_underflow(){
    Stack *stack = create_stack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    pop(stack);
    pop(stack);
    pop(stack);
    assert(stack->top == -1);
    printf("test_stack_underflow passed\n");
    free_stack(stack);
}

void test_all(void){
    test_pop();
    test_peek();
    test_is_empty();
    test_print_stack();
    test_free_stack();
    test_stack_overflow();
    test_stack_underflow();
    printf("All tests passed\n");
}

// test the stack 
int main(void) {

    test_all();

    return 0;
}


