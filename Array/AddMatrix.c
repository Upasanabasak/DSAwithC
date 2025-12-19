#include <stdio.h>

int main()
{
	int a[3][3], b[3][3], result[3][3];
	int i, j;
	
	printf("\nEnter 1st matrix elements: ");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("\nPosition [%d][%d]: ", i+1, j+1);
			scanf("%d", &a[i][j]);	
		}
	}
	
	printf("\nEnter 2nd matrix elements: ");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("\nPosition [%d][%d]: ", i+1, j+1);
			scanf("%d", &b[i][j]);	
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			result[i][j] = a[i][j] + b[i][j];
		}
	}
	
	printf("\n----------------------------");
	printf("\nAfter addition: \n");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ", result[i][j]);	
		}
		printf("\n");
	}
	
	return 0;
}
