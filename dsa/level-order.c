#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

// Function to check if a given array represents the level order traversal of a BST
bool isLevelOrderBST(int arr[], int n) {
    if (n == 0)
        return true;
    
    struct Node* root = NULL;
    root = insertNode(root, arr[0]);

    for (int i = 1; i < n; i++) {
        insertNode(root, arr[i]);
    }

    // Check if the BST property holds
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}

int main() {
    // Example level order traversal array
    int arr[] = {8, 5, 10, 3, 6, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isLevelOrderBST(arr, n))
        printf("Given array represents the level order traversal of a BST.\n");
    else
        printf("Given array does not represent the level order traversal of a BST.\n");

    return 0;
}