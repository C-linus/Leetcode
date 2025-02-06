#include <stdio.h>
#include <stdlib.h>



int min(int *arr,int size,int *minIndex)
{
	int min = *arr;
	int *minIndex = 0;
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

