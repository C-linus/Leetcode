#include <stdio.h>
#include <stdlib.h>

void init_arr(int *arr,int size,int value)
{
	for(int i = 0; i < size; i++)
	{
		*(arr + i) = value;
	}
}


int* pascal(int row_index)
{
	int *n_row = (int *) malloc(sizeof(int)*sizeof(row_index + 1));

	if(!n_row) return NULL;

	init_arr(n_row,row_index + 1,1);
	for(int i = 2; i <= row_index; i++)
	{
		for(int j = i-1; j > 0; j--)
		{
			*(n_row + j) = *(n_row + j) + *(n_row + j - 1);
		}
	}
	return n_row;
}
void print_arr(int* arr,int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ",*(arr + i));
	}
	printf("\n");
}

int main()
{
	int row_index;
	printf("Enter the row-no: ");
	scanf("%d",&row_index);
	int *n_row = pascal(row_index);
	print_arr(n_row,row_index+1);
	free(n_row);
	return EXIT_SUCCESS;
}
