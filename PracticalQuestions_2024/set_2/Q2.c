/* Write a program in C that takes as input a binary tree and traverse it using post-order traversal.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *createTree(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;

    return newNode;
};

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createTree(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)                  
        root->right = insert(root->right, value);
    return root;
}

void postOrder(struct Node* root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d->", root->data);
}

int main()
{
    int val;
    int choice;
    struct Node* root = NULL;
    do
    {
        printf("\n\t\t\t---Menu---");
        printf("\n1.Insert\n2.Postorder traversal\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
                printf("Enter the value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
        case 2:
                printf("Postorder traversal: ");
                postOrder(root);
                printf("\n");
                break;
        case 3:
                printf("\nExiting...");
                break;
        default:
                printf("\nInvalid number.\nPlease enter correct number(1-4).");
        }
    } while (choice != 3);
    return 0;
}