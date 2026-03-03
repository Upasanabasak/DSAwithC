/* Write a program in C to create a Binary Search Tree (BST) and incorporate the following operations:
(a) Searching for a specific item
(b) Performing inorder traversal (recursive)
(c) Delete an element
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory not available\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Inorder Traversal (Recursive)
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Search element
void search(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if (key == root->data)
        printf("Element found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Find minimum value node
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else
        {
            struct Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    do
    {
        printf("\n---- MENU ----");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Inorder Traversal");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(root, value);
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}