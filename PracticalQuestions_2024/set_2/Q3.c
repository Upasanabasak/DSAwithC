/* Input a list of numbers in arbitrary order and write a program in C to construct 
binary search tree from these numbers. Also write functions for insertion and 
deletion of elements from this constructed binary search tree.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
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

// Insert into BST
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

// Find minimum node (used in deletion)
struct Node* findMin(struct Node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int value)
{
    if(root == NULL)
        return NULL;

    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else
        {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Inorder traversal (prints sorted order)
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    int n, value, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    do
    {
        printf("\n\n--- MENU ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display (Inorder)");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}