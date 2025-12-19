// Multiply a3*2 , b2*3 matrix. Find maximum element in each rows.

#include <stdio.h>

int main()
{
	int r1, c1, r2,c2, max[10];
	int a[10][10], b[10][10], result[10][10];
	int i, j, k;
	
	// Taking 1st matrix row & column number
	printf("\nEnter 1st row & column element number: ");
	scanf("%d %d", &r1, &c1);
	
	// Taking 2nd matrix row & column number
	printf("\nEnter 2nd row & column element number: ");
	scanf("%d %d", &r2, &c2);
	
	//Check 1st matric column & 2nd matrix row are not equal then exit from the program
	if(c1 != r2)
	{
		printf("\nMatrix multiplication not possible (c1 != r2).");
		return 1;
	}
	
	// Taking 1st matrix elements	
	printf("\nEnter 1st matrix elements: ");
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c1; j++)
		{
			printf("\nPosition [%d][%d]: ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}
	
	// Taking 2nd matrix elements
	printf("\nEnter 2nd matrix elements: ");
	for(i = 0; i < r2; i++)
	{
		for(j = 0; j < c2; j++)
		{
			printf("\nPosition [%d][%d]: ", i+1, j+1);
			scanf("%d", &b[i][j]);
		}
	}
	
	// Initialize result matrix
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
		{
			result[i][j] = 0;
		}
	}
	
	//Matrix multiplication is done
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
		{
			for(k = 0; k < c1; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	//print the result
	printf("\n-----------------------------------------");
	printf("\nAfter matrix multiplication: \n");
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	//check maximum number in each rows
	for(i = 0; i < r1; i++)  // 2
	{
		max[i] = result[i][0];
		for(j = 0; j < c2; j++)  //2
		{
				if(result[i][j] > max[i]);  // t
					max[i] = result[i][j];
		}
	}
	
	//print maximum number in each rows
	printf("\nMaximum number in each rows: ");
	for(i = 0; i < r1; i++)
	{
		printf("\nRow %d: %d", i + 1,max[i]);
	}
	
	return 0;
}
