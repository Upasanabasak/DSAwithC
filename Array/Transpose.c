#include <stdio.h>

int main() 
{
    int n = 3;
    int matrix[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int temp;

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose Logic
    for (int i = 0; i < n; i++) 
    {
        // Start j at i + 1 to only swap elements above the diagonal
        for (int j = i + 1; j < n; j++) 
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
