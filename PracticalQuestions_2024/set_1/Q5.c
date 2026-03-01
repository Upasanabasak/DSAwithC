/* Write a program in C to create a Binary Search Tree (BST) and incorporate the following operations:
(a) Searching for a specific item
(b) Performing inorder traversal (recursive)
(c) Delete an element
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *createNoqde()
{
    struct Node *head = NULL;
    struct Node *newNode = NULL;
    struct Node *temp = NULL;
    char choice;
    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\nMemory is not available.");
            return;
        }
        else
        {
            printf("\nEnter the value: ");
            scanf("%d", &newNode->data);
            newNode->left = newNode->right = NULL;
            if (head == NULL)
            {
                head = temp = newNode;
            }
            else
            {
                temp->right = newNode;
                newNode->left = temp;
                temp = newNode;
            }
        }
        printf("\nDo you want to enter next data(Y/y) ? ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    return head;
};

void search()
{
    printf("\nEnter the element for searching");
}

int main()
{
    int num;
    int choice;
    create();
    do
    {
        printf("\n\t\t\t---Menu---");
        printf("\n1.Searching for a specific item\n2.Performing inorder traversal\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            search();
            break;
        case 2:
            inorder();
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