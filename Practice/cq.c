#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if Circular Queue is Full
int isFull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

// Check if Circular Queue is Empty
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

// Enqueue operation
void enqueue()
{
    int value;

    if (isFull())
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    if (front == -1)
    { // First element
        front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = value;
    printf("%d inserted successfully.\n", value);
}

// Dequeue operation
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
    { // Only one element
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Peek operation
void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Display Circular Queue
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are:\n");

    if (rear >= front)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i < MAX; i++)
            printf("%d ", queue[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}

// Main function using do-while
int main()
{
    int choice;

    do
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. isFull\n");
        printf("6. isEmpty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            if (isFull())
                printf("Queue is Full.\n");
            else
                printf("Queue is Not Full.\n");
            break;

        case 6:
            if (isEmpty())
                printf("Queue is Empty.\n");
            else
                printf("Queue is Not Empty.\n");
            break;

        case 7:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}