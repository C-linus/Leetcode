#include <stdio.h>
#include <stdlib.h>



void merge(int *num1,int *num2,int m,int n)
{
	int i =  m - 1 , j = n - 1, k = (m + n) -1;
	while ( j >= 0)
	{

		if (i >= 0 && *(num1 + i) >= *(num2 + j))
		{
			*(num1 + k) = *(num1 + i);
			i--;
		}
		else
		{
			*(num1 + k) = *(num2 + j);
			j--;
		}
		k--;
	}
}


void print_arr(int *arr,int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ",*(arr + i));
	}
	printf("\n");
}

int main()
{
	int num1[] ={1,2,3,0,0,0};
	int m = 3;
	int num2[] ={2,5,6};
	int n = 3;
	merge(num1,num2,m,n);
	print_arr(num1,m+n);
	return EXIT_SUCCESS;
}

