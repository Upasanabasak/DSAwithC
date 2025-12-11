#include <stdio.h>

int main() 
{
    int arr[50], n, pos, val, i;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Insertion
    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > n + 1) 
    {
        printf("Invalid position! Please enter between 1 and %d.\n", n + 1);
        return 0;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    // Shift elements to make space
    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    // Insert value
    arr[pos - 1] = val;
    n++;

    // Output the updated array
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
