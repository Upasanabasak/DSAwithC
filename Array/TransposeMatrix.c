#include <stdio.h>

int main()
{
	int a[3][3], transpose[3][3];
	int i, j;
	
	printf("\nEnter the elements: ");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("\nPosition [%d][%d]: ", i+1, j+1);
			scanf("%d", &a[i][j]);	
		}
	}
	
	printf("\n--------------------------");
	printf("\nOriginal matrix: \n");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);	
		}
		printf("\n");
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			transpose[j][i] = a[i][j];
		}
	}
	
	printf("\nAfter transpose matrix: \n");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ", transpose[i][j]);
		}
		printf("\n");
	}
	
	return 0;	
}
