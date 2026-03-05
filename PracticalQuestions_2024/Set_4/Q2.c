/*
    Implement a stack using a linked list with the following operations: Push, Pop, Peek, isEmpty, and Display.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push()
{
    int value;
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory are not available.");
        return;
    }
    printf("\nEnter the value: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\n%d is pushed successfully.", value);
}

void pop()
{
    if (isEmpty())
        printf("\nStack is Underflow.\nCannot delete.");
    else
    {
        struct Node *temp = NULL;
        temp = top;
        printf("\n%d is deleted", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (isEmpty())
        printf("\nStack Empty.");
    else
        printf("\nTop element in stack is: %d", top->data);
}

void display()
{
    struct Node *temp = NULL;
    if (isEmpty())
        printf("\nStack is Empty.");
    else
    {
        temp = top;
        printf("\nStack elements are: \n");
        while (temp != NULL)
        {
            printf("\n| %d |", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n\t\t\t---STACK MENU---");
        printf("\n1.PUSH\t2.POP\t3.PEEK\t4.isEmpty\t5.DISPLAY\t6.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
                printf("\nStack is Empty.");
            else
                printf("\nStack is not Empty.");
            break;
        case 5:
            display();
            break;
        case 6:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid number!\nEnter correct number(1 - 6).");
        }
    } while (choice != 6);
    return 0;
}