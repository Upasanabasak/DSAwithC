/* Write a program in C to perform merging of two singly linked list.
    The two input lists need to be created after taking the necessary details from the user.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* create()
{
    struct Node* newNode = NULL;
    struct Node *head = NULL;
    struct Node *temp = NULL;
    char choice;
    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if(newNode == NULL)
        {
            printf("\nMemory are not available.");
            exit(1);
        }
        printf("\nEnter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        printf("\nDo you want to enter the next data: ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    return head;
};

struct Node* merge(struct Node* head1, struct Node* head2)
{
    struct Node *temp = NULL;
    if(head1 == NULL)
        return head2;
    temp = head1;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

void display(struct Node *head)
{
    struct Node *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;

    printf("\nEnter the number for 1st linked list: ");
    head1 = create();

    printf("\nEnter the number for 2nd linked list: ");
    head2 = create();

    printf("\nThe elements in 1st node: ");
    display(head1);

    printf("\nThe elements in 2nd node: ");
    display(head2);

    printf("\nAfter merge 1st linked list & 2nd linked list: ");
    head3 = merge(head1, head2);
    display(head3);

    return 0;
}