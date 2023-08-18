// binary tree implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
} Node; 

struct node *root = NULL;

// function prototypes
void insert(int value);
void insertHelper(struct node *root, int value);
void printTree(struct node *root);
void printTreeHelper(struct node *root);
bool search(int value);
bool searchHelper(struct node *root, int value);
void delete(int value);
void deleteHelper(struct node *root, int value);
int findMin(struct node *root);
int findMax(struct node *root);

void insert(int value) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else {
        insertHelper(root, value);
    }
}

void insertHelper(struct node *root, int value) {
    if (value < root->value) {
        if (root->left == NULL) {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->value = value;
            newNode->left = NULL;
            newNode->right = NULL;
            root->left = newNode;
        } else {
            insertHelper(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->value = value;
            newNode->left = NULL;
            newNode->right = NULL;
            root->right = newNode;
        } else {
            insertHelper(root->right, value);
        }
    }
}

void printTree(struct node *root) {
    printTreeHelper(root);
}

void printTreeHelper(struct node *root) {
    if (root == NULL) {
        printf("\n");
    } else {
        printTreeHelper(root->left);
        printf("%d -> ", root->value);
        printTreeHelper(root->right);
    }
}

bool search(int value) {
    return searchHelper(root, value);
}

bool searchHelper(struct node *root, int value) {
    if (root == NULL) {
        return false;
    } else if (root->value == value) {
        return true;
    } else if (value < root->value) {
        return searchHelper(root->left, value);
    } else {
        return searchHelper(root->right, value);
    }
}

void delete(int value) {
    deleteHelper(root, value);
}

void deleteHelper(struct node *root, int value) {
    if (root == NULL) {
        return;
    } else if (value < root->value) {
        deleteHelper(root->left, value);
    } else if (value > root->value) {
        deleteHelper(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct node *temp = root;
            root = root->left;
            free(temp);
        } else {
            int min = findMin(root->right);
            root->value = min;
            deleteHelper(root->right, min);
        }
    }
}

int findMin(struct node *root) {
    if (root->left == NULL) {
        return root->value;
    } else {
        return findMin(root->left);
    }
}

int findMax(struct node *root) {
    if (root->right == NULL) {
        return root->value;
    } else {
        return findMax(root->right);
    }
}

int main(void) {
    insert(5);
    insert(3);
    insert(7);
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    printTree(root);
    printf("%d\n", search(5));
    printf("%d\n", search(3));
    printf("%d\n", search(7));
    printf("%d\n", search(2));
    printf("%d\n", search(4));
    printf("%d\n", search(6));
    printf("%d\n", search(8));
    printf("%d\n", search(1));
    printf("%d\n", search(9));
    delete(5);
    printTree(root);
    delete(3);
    printTree(root);
    delete(7);
    printTree(root);
    delete(2);
    printTree(root);
    delete(4);
    printTree(root);
    delete(6);
    printTree(root);
    delete(8);
    printTree(root);
    return 0;
}





