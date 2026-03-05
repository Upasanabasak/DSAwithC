/*
    Implement a Double-ended Queue (Deque) using a linked list with functions to insert
    and delete elements from both the front and rear.
*/

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

/* Front and Rear pointers */
struct Node *front = NULL;
struct Node *rear = NULL;

/* Insert at Front */
void insertFront(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL)
    {
        rear = newNode;
    }
    else
    {
        front->prev = newNode;
    }

    front = newNode;
    printf("Inserted %d at front\n", value);
}

/* Insert at Rear */
void insertRear(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL)
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }

    rear = newNode;
    printf("Inserted %d at rear\n", value);
}

/* Delete from Front */
void deleteFront()
{
    if (front == NULL)
    {
        printf("Deque is Empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted %d from front\n", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

/* Delete from Rear */
void deleteRear()
{
    if (rear == NULL)
    {
        printf("Deque is Empty!\n");
        return;
    }

    struct Node *temp = rear;
    printf("Deleted %d from rear\n", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
}

/* Display Deque */
void display()
{
    if (front == NULL)
    {
        printf("Deque is Empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("Deque elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main Function */
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Insert Front\n2. Insert Rear\n");
        printf("3. Delete Front\n4. Delete Rear\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}