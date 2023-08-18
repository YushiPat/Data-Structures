// avl tree implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node {
    int value;
    int height;
    struct node *left;
    struct node *right;
} Node;

struct node *root = NULL;

// function prototypes
void insert(int value);
void insertHelper(struct node *root, int value);
void printTree(struct node *root);
void printTreeHelper(struct node *root);
int height(struct node *root);
int max(int a, int b);
struct node *rightRotate(struct node *root);
struct node *leftRotate(struct node *root);
int getBalance(struct node *root);


void insert(int value) {
    insertHelper(root, value);
}

void insertHelper(struct node *root, int value) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->value = value;
        root->height = 0;
        root->left = NULL;
        root->right = NULL;
    } else if (value < root->value) {
        insertHelper(root->left, value);
    } else {
        insertHelper(root->right, value);
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && value < root->left->value) {
        rightRotate(root);
    }
    if (balance < -1 && value > root->right->value) {
        leftRotate(root);
    }
    if (balance > 1 && value > root->left->value) {
        root->left = leftRotate(root->left);
        rightRotate(root);
    }
    if (balance < -1 && value < root->right->value) {
        root->right = rightRotate(root->right);
        leftRotate(root);
    }
}

void printTree(struct node *root) {
    printTreeHelper(root);
    printf("\n");
}

void printTreeHelper(struct node *root) {
    if (root == NULL) {
        return;
    }
    printTreeHelper(root->left);
    printf("%d ", root->value);
    printTreeHelper(root->right);
}

int height(struct node *root) {
    if (root == NULL) {
        return -1;
    }
    return root->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

struct node *rightRotate(struct node *root) {
    struct node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}


struct node *leftRotate(struct node *root) {
    struct node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

int getBalance(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    printTree(root);
    return 0;
}





