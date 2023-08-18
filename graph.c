// graph data structure implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node {
    int value;
    struct node *next;
} Node;

struct node *graph = NULL;

// function prototypes
void addEdge(int src, int dest);
void printGraph();
void printGraphHelper(struct node *graph);
void removeEdge(int src, int dest);
void removeEdgeHelper(struct node *graph, int src, int dest);
bool hasEdge(int src, int dest);
bool hasEdgeHelper(struct node *graph, int src, int dest);

void addEdge(int src, int dest) {
    if (graph == NULL) {
        graph = (struct node *)malloc(sizeof(struct node));
        graph->value = src;
        graph->next = (struct node *)malloc(sizeof(struct node));
        graph->next->value = dest;
        graph->next->next = NULL;
    } else {
        struct node *temp = graph;
        while (temp->value != src) {
            temp = temp->next;
        }
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = dest;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printGraph() {
    printGraphHelper(graph);
}

void printGraphHelper(struct node *graph) {
    if (graph == NULL) {
        printf("\n");
    } else {
        printf("%d -> ", graph->value);
        printGraphHelper(graph->next);
    }
}

void removeEdge(int src, int dest) {
    removeEdgeHelper(graph, src, dest);
}

void removeEdgeHelper(struct node *graph, int src, int dest) {
    if (graph == NULL) {
        return;
    } else if (graph->value == src) {
        struct node *temp = graph;
        while (temp->next->value != dest) {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    } else {
        removeEdgeHelper(graph->next, src, dest);
    }
}

bool hasEdge(int src, int dest) {
    return hasEdgeHelper(graph, src, dest);
}

bool hasEdgeHelper(struct node *graph, int src, int dest) {
    if (graph == NULL) {
        return false;
    } else if (graph->value == src) {
        struct node *temp = graph;
        while (temp->next != NULL) {
            if (temp->next->value == dest) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    } else {
        return hasEdgeHelper(graph->next, src, dest);
    }
}

int main() {
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 1);
    printGraph();
    printf("%d\n", hasEdge(1, 2));
    printf("%d\n", hasEdge(1, 4));
    printf("%d\n", hasEdge(4, 1));
    removeEdge(1, 2);
    printGraph();
    printf("%d\n", hasEdge(1, 2));
    return 0;
}