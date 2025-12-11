#include <stdio.h>
#include <math.h>
#define DEGREE 4

int main()
{
    int coefficients[5];
    int i;
    int sum = 0, x = 2;

    printf("\nEnter %d coefficient: ", DEGREE+1);
    for(i = 0; i <= DEGREE; i++)
    {
        printf("\nCoefficient of x^%d: ",i);
        scanf("%d", &coefficients[i]);
    }

    // printf()
    for(i = 0; i <= DEGREE; i++)
    {
        sum += coefficients[i] * (int) pow(x, i);
    }

    printf("\nValue of the polynomial at x = %d is %d", x, sum);
    return 0;
}