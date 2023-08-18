// heap implementation in c
// header file

#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct heap {
    int size;
    int capacity;
    int *data;
} Heap;

// function prototypes
void createHeap(int capacity);
void destroyHeap();
void insert(int value);
void heapifyUp();
void heapifyDown();
int extractMax();
void swap(int index1, int index2);
int parent(int index);
int leftChild(int index);
int rightChild(int index);
bool hasLeftChild(int index);
bool hasRightChild(int index);
void printHeap();


#endif
