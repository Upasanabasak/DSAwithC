#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int coeff;
    int exp;
    struct Node *next;
};

void display(struct Node *ptr)
{   
    printf("%dx%d", ptr->coeff, ptr ->exp); //printing the 1st term
    ptr = ptr -> next;

    while(ptr)
    {
        printf("+ %dx%d", ptr -> coeff,ptr ->exp); //printing the rest term
        ptr = ptr -> next;
    }
    printf("\n");
}
int Eval(struct Node *ptr, int x)
{
    int val = 0;
    while(ptr)
    {
        val += ptr -> coeff * pow(x, ptr -> exp);
        ptr = ptr -> next;
    }
    return val;
}

int main()
{
    struct Node *t,*last = NULL, *head = NULL;
    int num, i, x;

    printf("\nEnter the number of terms: ");
    scanf("%d", &num);

    printf("\nEnter the coeff.and exp for each term: ");

    for(i = 0; i <num; i++)
    {
        printf("\nFor term %d: ", i+1); //1st
        t = (struct Node *)malloc(sizeof(struct Node)); //memory allocation
        scanf("%d %d", &t ->coeff, &t ->exp); //stroing the coeff and exp of each term
        t -> next = NULL;

        if(head == NULL)
        {
            head = last = t;
        }

        else
        {
            last -> next = t;
            last = t;
        }
    }

    display(head);
    printf("\nEnter value of x: ");
    scanf("%d", &x);

    printf("\nThe value of the polynomial: %d", Eval(head,x));

    return 0;
}
