#include <stdio.h>
#include <stdlib.h>


unsigned int find_missing_number(unsigned int* arr, unsigned int length)
{
	unsigned int sum = 0;
	for(unsigned int i = 0; i < length; i++)
	{
		sum += *(arr + i);
	}
	return ((length * ( length + 1 ) / 2) - sum);
}



int main()
{
	unsigned int arr[] = {9,6,4,2,3,5,7,0,1};
	unsigned int length = sizeof(arr) / sizeof(int);
	printf("The missing number in the sequence is:%u\n",find_missing_number(arr,length));
	return EXIT_SUCCESS;
} 
