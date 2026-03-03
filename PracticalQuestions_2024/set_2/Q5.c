/*Write a C program to calculate the height of a binary tree. Ensure the program handles empty trees gracefully.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node (for building the tree)
struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to calculate height
int height(struct Node* root)
{
    if(root == NULL)
        return -1;   // height of empty tree

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main()
{
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Tree is empty.\n");
        printf("Height = -1\n");
        return 0;
    }

    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Height of the tree = %d\n", height(root));

    return 0;
}