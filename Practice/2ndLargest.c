#include <stdio.h>
#include <limits.h>
//  -2147483648
//  2147483647

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Second largest element not possible.\n");
        return 0;
    }

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);
    }
// 4 23 55 289 50 
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest; // -2.... , 4, 23, 55,
            largest = arr[i]; //4 , 23, 55, 289
        } 
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        printf("No distinct second largest element found.\n");
    } else {
        printf("Second largest element is: %d\n", secondLargest);
    }

    return 0;
}