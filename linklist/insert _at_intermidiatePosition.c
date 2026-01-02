#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *ptr;
};

int main()
{
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *forth = NULL;
    int k, i;
    int newVal;
    int past, future;

    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    forth = (struct Node*) malloc(sizeof(struct Node));

    printf("\nEnter the location of insertion(1-4): ");
    scanf("%d",&k);

    printf("\nEnter the value of the new node to insert: ");
    scanf("%d", &newVal); 

    for(i = 0; i != NULL;i++)
    {
        if( i == k)
        {
            past = i - 1;
            future = i + 1;
        }
    }

    past -> ptr = newval;
    return 0;
}