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
    struct Node* next;
};

struct Node* head = NULL;
struct Node* temp = NULL;

void push()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("\nMemory is no available.");
        return;
    }
    printf("\nEnter the Roll Number: ");
    scanf("%d", &newNode->rollNo);
    printf("\nEnter your name: ");
    scanf("%s", &newNode->name);
    newNode->next = head;
    head = newNode;
    printf("\nNode Pushed Successfully.");
}

void pop()
{
    if(head == NULL)
    {
        printf("\nStack Underflow.");
        return;
    }
    temp = head;
    printf("\nDeleted Record -> Roll No: %d, Name: %s", temp->rollNo, temp->name);

    head = head->next;
    free(temp);
}

void display()
{
    if(head == NULL)
        printf("\nStack is Empty.");
    temp = head;
    printf("\n\nStack Elements:\n");
    printf("\nRoll No.\tName");
    printf("\n-------------------------");
    while(temp != NULL)
        {
            printf("\n| %d\t\t%s |", temp->rollNo, temp->name);
            temp = temp->next;
        }
   }

void reverse()
{
    printf("\nHi");
}

int main()
{
    int choice;
    do
    {
        printf("\n\t\t\t---Menu---");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Reverse\n5.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
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
                    printf("\nExiting...");
                    break;
            default:
                    printf("\nInvalid Number!\nEnter correct number(1-5).");
        }
    }while(choice != 5);
    return 0;
}