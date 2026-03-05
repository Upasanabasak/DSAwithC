/*
Write a menu driven program in C to perform the following operations in a Stack using linked list with the node
structure (Roll, Name, Next):
    (a) Push
    (b) Pop
    (c) Display
    (d) Reverse
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int rollNo;
    char name[30];
    struct Node *next;
};

struct Node *head = NULL;

void push()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory not available.");
        return;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &newNode->rollNo);
    printf("Enter Name: ");
    scanf("%s", newNode->name); // Removed &

    newNode->next = head;
    head = newNode;
    printf("Node Pushed Successfully.\n");
}

void pop()
{
    if (head == NULL)
    {
        printf("\nStack Underflow.\n");
        return;
    }
    struct Node *temp = head;
    printf("\nPopped -> Roll: %d, Name: %s\n", temp->rollNo, temp->name);
    head = head->next;
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("\nStack is Empty.\n");
        return; // Added return
    }
    struct Node *temp = head;
    printf("\nStack Elements:\nRoll No.\tName\n-------------------------");
    while (temp != NULL)
    {
        printf("\n| %d\t\t%s |", temp->rollNo, temp->name);
        temp = temp->next;
    }
    printf("\n");
}

void reverse()
{
    if (head == NULL || head->next == NULL)
    {
        printf("\nStack reversed (or too short to change).\n");
        return;
    }
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next; // Store next
        current->next = prev; // Reverse pointer
        prev = current;       // Move prev forward
        current = next;       // Move current forward
    }
    head = prev;
    printf("\nStack Reversed Successfully.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n---Menu---\n1.Push\n2.Pop\n3.Display\n4.Reverse\n5.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1)
            break; // Basic input validation

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}