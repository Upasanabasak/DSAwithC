#include <stdio.h>

int main()
{
	int num, i, key, flag = 0;
	int arr[30];
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &num);
	
	printf("\nEnter the elements: ");
	for(i = 0; i < num; i++)
	{
		printf("\nPosition [%d] : ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\nEnter the search element: ");
	scanf("%d", &key);
	
	for(i = 0; i < num; i++)
	{
		if(arr[i] == key)
			flag = 1;
	}
	
	if(flag == 1)
		printf("\n%d is found at %d position.", key, i);
	else
		printf("\n%d is not found.", key);
	return 0;
}
