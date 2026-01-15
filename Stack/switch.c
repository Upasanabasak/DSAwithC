#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int top = -1;
int stack[SIZE];

bool isFull()
{
    if(top== SIZE-1)
    {
        printf("\nStack is Overflow.");
        return true;
    }
    printf("\nStack is not Overflow.");
    return false;
}

bool isEmpty()
{
    if(top == -1)
    {
        printf("\nStack is Empty.");
        return true;
    }
    printf("\nStack is not Empty.");
    return false;
}

void push()
{
    int num;

    if(top == SIZE - 1)
        isFull();
    else
    {
        printf("\nEnter the element: ");
        scanf("%d", &num);
        stack[++top] = num;
        printf("%d pushed",num);
    }
}

void pop()
{
    if(top == -1)
        printf("\nStack Underflow");
    else
        printf("\n%d pop", stack[top--]);
}

bool peek()
{
    if(top == -1)
    {
        isEmpty();
        printf("\nSo, Peek is not available now.");
        printf("\nPlease enter atleast one element.");
        push();
        return true;
    }
    printf("%d is top of the stack", stack[top]);
    return false;
}

void display()
{
    int i;

    if(top == -1)
        isEmpty();
    else
    {
        for(i = top; i >= 0; i--)
        {
            printf("\n|%d|",stack[i]);
        }
    }
}

int main()
{
    int choice;

    do{
        printf("\n\t---MENU---");
        printf("\n1.PUSH\t2.POP\t3.PEEK\t4.DISPLAY\t5.EXIT");

        printf("\nEnter your choice: ");
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
                    peek();
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    printf("\nExit...");
                    break;
            default:
                    printf("\nInvalid choice.\nPlease enter correct number(1-5).");
        }
    }while(choice != 5);

    return 0;
}
