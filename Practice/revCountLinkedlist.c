/*C Function to Print Linked List in Reverse and Count Nodes*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int nodeCount = 0;

struct Node *create()
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    char choice;

    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\nMemory is not available.");
            return NULL;
        }

        printf("Enter the value: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to add another node? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return head;
}

void printReverseAndCount(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    nodeCount++;

    printReverseAndCount(ptr->next);

    printf("%d ", ptr->data);
}

int main()
{
    struct Node *head = NULL;

    printf("--- Create Linked List ---\n");
    head = create();

    if (head != NULL)
    {
        printf("\nLinked List in Reverse Order: ");
        printReverseAndCount(head);
        printf("\nTotal number of nodes: %d\n", nodeCount);
    }

    return 0;
}