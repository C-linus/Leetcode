#include <stdio.h>
#include <stdlib.h>

void swap(int*a , int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void move_zeros(int *arr,unsigned int length)
{
	unsigned int position = 0;
	for(unsigned int i = 0; i < length; i++)
	{
		if(*(arr + i) != 0)
		{
			swap((arr + position),(arr + i));
			position++;
		}
	}
}

void print_arr(int* arr,unsigned int length)
{
	for(unsigned int i = 0; i < length; i++)
	{
		printf("%d ",*(arr + i));
	}
	printf("\n");
}

int main()
{
	int arr[] = {0};
	unsigned int length = sizeof(arr) / sizeof(int);
	move_zeros(arr,length);
	print_arr(arr,length);
	return EXIT_SUCCESS;
}
