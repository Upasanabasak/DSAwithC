#include <stdio.h>

int main()
{
    int num, arr[50], i;

    printf("\nEnter size of the array: ");
    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        printf("\nEnter numbers: ");
        scanf("%d", &arr[i]);
    }

    printf("\n------------------------------");
    printf("\nElements are: ");
    for(i = 0; i < num; i++)
    {
        printf("\nPosition %d is : %d", i+1, arr[i]);
    }
    return 0;
}