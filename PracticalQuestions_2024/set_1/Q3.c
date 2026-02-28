/* Write a program in C to implement circular queue using array,
    and handle all possible exceptions / error cases.
*/

#include <stdio.h>

int cq[20], i, size;
int front = -1, rear = -1;

void enqueue()
{
    int num;
    if((rear + 1) % size == front)
        printf("\nCircular Queue is Full.");
    else
    {
        printf("\nEnter the number: ");
        scanf("%d", &num);
        if(front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % size;
        cq[rear] = num;
        printf("\n%d is inserted", num);
    }
}

void dequeue() 
{
    if(front == -1)
        printf("Circular Queue is Underflow.");
    else
    {
        printf("%d is deleted.", cq[front]);
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
}

void display()
{
    if(front == -1)
        printf("\nCircular Queue is Empty.");
    else
    {
        printf("\nThe elements are: ");
        i = front;
        while(1)
        {
            printf("%d ", cq[i]);
            if(i == rear)
                break;
            i = (i + 1) % size;
        }
    }
}

int main()
{
    int choice;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    do {
        printf("\n\t---Menu---");
    printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit");
    printf("\nEnter the choice: ");
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
        display();
        break;
    case 4:
        printf("\nExiting...");
        break;
    default:
        printf("Invalid number.\nEnter correct number(1-4).");
    }
    }while(choice != 4);
    return 0;
}