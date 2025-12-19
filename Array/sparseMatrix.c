#include <stdio.h>
#define MAX 5 //maximun rows & columns allowed

int main()
{
    int arr[MAX][MAX], triplet[MAX][MAX];
    int rows, cols;
    int i, j, nz = 0;
    int c1 = 0, c2 = 0;

    printf("\nEnter rows & columns number: ");
    scanf("%d %d", &rows, &cols);

    if(rows > MAX || cols > MAX)
    {
        printf("\nInvalid rows & columns number.");
        return 1;
    }

    printf("\nEnter elements: ");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("\nPosition array[%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
            //check if the number of 0's greater than non- zero's
            if(arr[i][j] == 0)
            	c1++;
            else 
            	c2++;
        }
    }
    
    if(c1 > c2)
    {
    	printf("\nIt is a sparse Matrix.");
    	for(i = 0; i < rows; i++)
	    {
	        for(j = 0; j < cols; j++)
	        {
	    		if(arr[i][j] != 0)
	            {
	                triplet[0][nz] = i;
	                triplet[1][nz] = j;
	                triplet[2][nz] = arr[i][j];
	                nz++;
	            }
	        }
		}
		printf("\nOriginal Matrix: \n");
	    for(i = 0; i < rows; i++)
	    {
	        for(j = 0; j < cols; j++)
	        {
	            printf("%d\t", arr[i][j]);
	        }
	        printf("\n");
	    }
	
	    printf("\n-------------------------");
	    printf("\nTriplet Representation: \n");
	    printf("\nRow\tCol\tValue\n");
	    for(i = 0; i < nz; i++)
	    {
	        printf("%d\t%d\t%d\n", triplet[0][i], triplet[1][i], triplet[2][i]);
	    }
	}
	else
	{
		printf("\nIt is not a sparse Matrix.\nPlease enter correct numbers.");
		return 1;
	}

    return 0;
}
