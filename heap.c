// heap implementation in C NOT C++

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "heap.h"

// heap sturcture



void createHeap(int capacity) {
    Heap.size = 0;
    Heap.capacity = capacity;
    Heap.data = (int *)malloc(sizeof(int) * capacity);
}

void destroyHeap() {
    free(Heap.data);
}

void insert(int value) {
    assert(Heap.size < Heap.capacity);
    Heap.data[Heap.size] = value;
    Heap.size++;
    heapifyUp();
}

void heapifyUp() {
    int index = Heap.size - 1;
    while (index > 0 && Heap.data[index] > Heap.data[parent(index)]) {
        swap(index, parent(index));
        index = parent(index);
    }
}

void heapifyDown() {
    int index = 0;
    while (hasLeftChild(index)) {
        int largerChildIndex = leftChild(index);
        if (hasRightChild(index) && rightChild(index) > leftChild(index)) {
            largerChildIndex = rightChild(index);
        }
        if (Heap.data[index] > Heap.data[largerChildIndex]) {
            break;
        } else {
            swap(index, largerChildIndex);
        }
        index = largerChildIndex;
    }
}

int extractMax() {
    assert(Heap.size > 0);
    int max = Heap.data[0];
    Heap.data[0] = Heap.data[Heap.size - 1];
    Heap.size--;
    heapifyDown();
    return max;
}

void swap(int index1, int index2) {
    int temp = Heap.data[index1];
    Heap.data[index1] = Heap.data[index2];
    Heap.data[index2] = temp;
}

int parent(int index) {
    return (index - 1) / 2;
}

int leftChild(int index) {
    return index * 2 + 1;
}


int rightChild(int index) {
    return index * 2 + 2;
}

bool hasLeftChild(int index) {
    return leftChild(index) < Heap.size;
}

bool hasRightChild(int index) {
    return rightChild(index) < Heap.size;
}

void printHeap() {
    for (int i = 0; i < Heap.size; i++) {
        printf("%d ", Heap.data[i]);
    }
    printf("\n");
}

void test_heap(){
    createHeap(10);
    for (int i = 0; i < 10; i++) {
        insert(i);
    }
    printHeap();
    for (int i = 0; i < 10; i++) {
        printf("%d ", extractMax());
    }
    printf("\n");
    destroyHeap();

}

int main() {
    test_heap();
    return 0;
}


