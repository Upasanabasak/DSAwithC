/*
Write a menu driven program in C to perform the following operations on Matrix. Assume the contents are integer.
Check the necessary condition for performing the addition and multiplication operations:
    (a) Initialize
    (b) Addition
    (c) Multiplication
*/
#include <stdio.h>

int mat1[10][10], mat2[10][10], res[10][10];
int r1, c1, r2, c2;

// Function to initialize matrices
void initialize()
{
    int i, j;

    printf("\nEnter rows and columns for Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of Matrix 1:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);

    printf("\nEnter rows and columns for Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of Matrix 2:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);

    printf("\nMatrices Initialized Successfully.\n");
}

// Function to add matrices
void addition()
{
    int i, j;

    if (r1 != r2 || c1 != c2)
    {
        printf("\nMatrix addition not possible! Dimensions must be equal.\n");
        return;
    }

    printf("\nResult of Matrix Addition:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply matrices
void multiplication()
{
    int i, j, k;

    if (c1 != r2)
    {
        printf("\nMatrix multiplication not possible! Columns of Matrix1 must equal rows of Matrix2.\n");
        return;
    }

    // Initialize result matrix with zeros
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            res[i][j] = 0;

    // Multiply
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < c1; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("\nResult of Matrix Multiplication:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d\t", res[i][j]);
        printf("\n");
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n\n\t--- Matrix Menu ---");
        printf("\n1. Initialize Matrices");
        printf("\n2. Addition");
        printf("\n3. Multiplication");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            initialize();
            break;
        case 2:
            addition();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            printf("\nExiting program...\n");
            break;
        default:
            printf("\nInvalid choice! Enter 1-4.");
            break;
        }
    } while (choice != 4);

    return 0;
}