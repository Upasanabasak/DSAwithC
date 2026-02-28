/* Write a program in C to implement the Push, Pop and Display operations of a stack. 
    After this reverse the order of the first stack, using an additional stack.
*/

#include <stdio.h>

int size;
int top1 = -1, top2 = -1;
int stack[20];
int revStack[20];

void push()
{
    int x;
    if(top1 == size - 1)
        printf("\nStack is full");
    else
    {
        printf("Enter the element: ");
        scanf("%d", &x);
        stack[++top1] = x;
        printf("\n%d is pushed.", x); 
    }
}
void pop()
{
    if(top1 == -1)
        printf("\nStack is Underflow.");
    else
        printf("\n%d is poped.", stack[top1--]);
}
void reverse()
{
    if(top1 == -1)
        printf("\nStack is Empty.");
    else
    {
        while(top1 != -1)
            revStack[++top2] = stack[top1--];
        while(top2 != -1)
            stack[++top1] == revStack[top2--];
        printf("\nStack has been reversed.");
    }
    
}

void display()
{
    int i;
    printf("\nThe elements are: \n");
    for(i = top1; i >= 0; i--)
        printf("\n| %d |", stack[i]);
}

int main()
{
    int choice;
    printf("Enter the size of stack: ");
    scanf("%d", &size);

    do {
        printf("\n\t\t---Menu---");
        printf("\n1.Push\t2.Pop\t3.Reverse the order of the first stack, using an additional stack\t4.Display\t4.Exit");
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
                    reverse();
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    printf("Exiting...");
                    break;
            default:
                    printf("\nInvalid number.\nEnter correct number(1-5).");
        }
    }while(choice != 5);
    return 0;
}