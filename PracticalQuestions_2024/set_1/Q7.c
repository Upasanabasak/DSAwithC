/* Write a program in C to create a doubly linked list with ‘n’ nodes (n → to be taken
as the input from the user), and perform the following operations:
    (a) Insert a new node at a specific position, say “pos”. The validity of “pos” must be checked
        and handled accordingly.
    (b) Display the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
};

struct Node *create(int n)
{
    struct Node *head = NULL, *newNode = NULL, *temp = NULL;
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->previous = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->previous = temp;
            temp = newNode;
        }
    }
    return head;
}

struct Node *insertAtPosition(struct Node *head)
{
    int val, pos, i;
    struct Node *newNode, *temp = head;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return head;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &val);
    newNode->data = val;

    // Case 1: Insert at beginning
    if (pos == 1)
    {
        newNode->next = head;
        newNode->previous = NULL;
        if (head != NULL)
            head->previous = newNode;
        return newNode; // New head
    }

    // Case 2: Traverse to pos-1
    for (i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    // Case 3: Insert after temp
    newNode->next = temp->next;
    newNode->previous = temp;
    if (temp->next != NULL)
    {
        temp->next->previous = newNode;
    }
    temp->next = newNode;

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    printf("\nList: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = create(n);
    display(head);

    do
    {
        printf("\n---Menu---\n1. Insert\n2. Display\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertAtPosition(head); // Update head in main
            break;
        case 2:
            display(head);
            break;
        case 3:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}