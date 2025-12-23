#include <stdio.h>

int main()
{
    int arr[100], num, pos, i;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    printf("Enter elements:\n");
    for(i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to delete (1 to %d): ", num);
    scanf("%d", &pos);

    if(pos < 1 || pos > num)
    {
        printf("Invalid position");
        return 1;
    }

    // shift elements left
    for(i = pos - 1; i < num - 1; i++)
        arr[i] = arr[i + 1];

    num--;

    printf("Array after deletion:\n");
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);

    return 0;
}

