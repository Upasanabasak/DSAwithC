/*Write a C program to delete the n-th element of a circular queue.
Firstly, this code checks if the queue is empty or if the position to delete is invalid.
If the position is valid, it deletes the first $(n - 1)$ elements, then deletes the
n-th element by calling the dequeue() function.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Function to check if queue is empty */
int isEmpty()
{
    return (front == -1);
}

/* Function to check if queue is full */
int isFull()
{
    return ((rear + 1) % MAX == front);
}

/* Enqueue function */
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is Full!\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
}

/* Dequeue function */
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty!\n");
        return -1;
    }

    int data = queue[front];

    if (front == rear)
    {
        front = rear = -1; // Queue becomes empty
    }
    else
    {
        front = (front + 1) % MAX;
    }

    return data;
}

/* Function to count number of elements */
int size()
{
    if (isEmpty())
        return 0;
    if (rear >= front)
        return (rear - front + 1);
    return (MAX - front + rear + 1);
}

/* Function to delete n-th element */
void deleteNth(int n)
{
    int count = size();

    if (isEmpty())
    {
        printf("Queue is Empty!\n");
        return;
    }

    if (n <= 0 || n > count)
    {
        printf("Invalid Position!\n");
        return;
    }

    // Move first (n-1) elements to rear
    for (int i = 1; i < n; i++)
    {
        enqueue(dequeue());
    }

    // Delete the n-th element
    int deleted = dequeue();
    printf("Deleted element: %d\n", deleted);
}

/* Display queue */
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty!\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice, value, n;

    while (1)
    {
        printf("\n1. Enqueue\n2. Delete N-th Element\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &n);
            deleteNth(n);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}