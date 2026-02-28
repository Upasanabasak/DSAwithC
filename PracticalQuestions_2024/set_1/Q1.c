/* Write a menu driven program in C to perform the following functions on an array given as input by the user:

(a) Print the 2nd largest number without sorting.
(b) Display the array in reverse order.
(c) Count the number of odd-elements present in even-valued array index. 
*/

#include <stdio.h>

int arr[20], i;

void secondLargest() {
    printf("Hello");
}

void reverseOrder(int arr[], int n) {
    printf("\nReverse Order: \n");
    for(i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
}

void oddCount(int arr[], int n) {
   int count = 0;
   for(i = 0; i < n; i++)
   if(i % 2 == 0 && arr[i] % 2 != 0) {
    count++;
   }
   printf("\nThe number of odd-elements present in even-valued array index is: %d", count);
}

int main()
{
    int choice, n;
    printf("\nEnter the array size: ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    do {
        printf("\n\t\t\t---Menu---");
        printf("\n1.Print 2nd largest\n2.Display array in reverse Order\n3.Count odd elements at even index");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                    secondLargest();
                    break;
            case 2:
                    reverseOrder( arr, n);
                    break;
            case 3:
                    oddCount(arr, n);
                    break;
            case 4: 
                    printf("\nExiting...");
                    break;
            default:
                    printf("\nInvalid number.\nEnter correct number(1-4).");
        }
    }while(choice != 4);
    return 0;
}