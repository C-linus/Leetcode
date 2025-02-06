#include <stdio.h>
#include <stdlib.h>



int min(int *arr,int size,int *minIndex)
{
	int min = *arr;
	*minIndex = 0;
	for(int i = 1; i < size; i++)
	{
		if(min > *(arr + i))
		{
			min = *(arr + i);
			*minIndex = i;
		}
	}
	return min;
}




int profit(int *arr, int size)
{
	int minimum,minIndex,maximum = 0;

	// To find the correct day to buy stock
	minimum = min(arr,size,&minIndex);

	// To find the correct day to sell stock (Maximum profit)
	for(int j = (minIndex + 1); j < size; j++)
	{
		if (maximum < *(arr + j))
			maximum = *(arr + j);
	}

	return (maximum != 0) ? (maximum - minimum) : 0;
}

int main()
{
	int arr[] = {7,6,4,3,1};
	int size = sizeof(arr) / sizeof(int);
	printf("The profit is:%d\n",profit(arr,size));
	return EXIT_SUCCESS;
}
