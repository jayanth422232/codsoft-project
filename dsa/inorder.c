#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into a BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to perform in-order traversal of BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    // Example BST
    struct Node* root = NULL;
    root = insertNode(root, 8);
    insertNode(root, 5);
    insertNode(root, 10);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 9);
    insertNode(root, 12);

    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
