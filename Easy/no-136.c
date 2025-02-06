#include <stdio.h>
#include <stdlib.h>

int find_non_duplicate(int *arr,int size)
{
	int non_duplicate = 0;
	for(int i = 0; i < size; i++)
	{
		non_duplicate ^= *(arr + i);
	}
	return non_duplicate;
}


int main()
{
	int arr[] = {4,1,2,1,2};
	int size = sizeof(arr) / sizeof(int);
	printf("The non repeating number is:%d\n",find_non_duplicate(arr,size));
	return EXIT_SUCCESS;
}
