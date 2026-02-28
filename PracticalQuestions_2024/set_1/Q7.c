/* Write a program in C to create a doubly linked list with ‘n’ nodes (n → to be taken 
as the input from the user), and perform the following operations:
    (a) Insert a new node at a specific position, say “pos”. The validity of “pos” must be checked 
        and handled accordingly.
    (b) Display the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* previous;
    int data;
    struct Node* next; 
};

struct Node* create() 
{
    struct Node* head = NULL;
    struct Node* newNode = NULL;
    struct Node* temp = NULL;
    char choice;
    do {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("\nMemory is not available.");
        exit(1);
    }
    else
    {
        printf("\nEnter the value: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->previous = NULL;
        if(head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            newNode->previous = temp;
            temp = newNode;
        }
        printf("\nDo you want to enter next data: ");
        scanf(" %c", &choice);
    }
    }while(choice == 'Y' || choice == 'y');
    return head;
};

struct Node* insertAtPosition()
{
    int val, pos;
    printf("\nEnter the the position: ");
    scanf("%d", &pos);
    printf("\nEnter the value: ");
    scanf("%d", &val);
}

int display(struct Node* head)
{
    struct Node* temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct Node* head;
    int choice;
    head = create();
    display(head);
    do {
        printf("\n\t\t\t---Menu---");
        printf("\n1.Insert a new node at a specific position\t2.Display the list\n3.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                    insertAtPosition();
                    break;
            case 2: 
                    dispaly();
                    break;
            case 3:
                    printf("\nExiting...");
                    break;
            default:
                    printf("\nInvalid number.\nEnter correct number(1-5).");
        }
    }while(choice != 3);
    return 0;
}