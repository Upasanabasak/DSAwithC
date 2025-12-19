#include <stdio.h>

int main()
{
	int arr[40];
	int num, temp;
	int i;
	
	printf("\nEnter total number of elements: ");
	scanf("%d", &num);
	
	printf("\nEnter elements: ");
	for(i = 0; i < num; i++)
	{
		printf("\nPosition %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\nBefore sorting: ");
	for(i = 0; i < num; i++)
	{
		printf("%d ",arr[i]);
	}
	
	for(i = 0; i < num; i++)
	{
		if(arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;	
		}
	}
	
	printf("\n-----------------------------------------");
	printf("\nAfter sorting: ");
	for(i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
