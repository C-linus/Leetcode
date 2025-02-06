#include <stdio.h>
#include <stdlib.h>

int** alloc_pascal_triangle(int nrows)
{
	int** pascal_triangle = (int **) malloc(sizeof(int *) * nrows);

	// NULL PTR CHECK
	if(!pascal_triangle) return NULL;

	for(int i = 0; i < nrows; i++)
	{
		*(pascal_triangle + i) = (int *) malloc(sizeof(int) * (i+1));

		// NULL PTR CHECK

		if(!(*pascal_triangle + i))
		{
			for(int j = 0; j < i; j++)
			{
				free(*(pascal_triangle + j));
			}
			free(pascal_triangle);
			return NULL;
		}
	}
	return pascal_triangle;
}

void free_pascal_triangle(int*** pascal_triangle,int nrows)
{
	for(int i = 0; i < nrows; i++)
	{
		free(*(*pascal_triangle + i));
	}
	free(*pascal_triangle);

	// Avoid Dangling PTR

	*pascal_triangle = NULL;

}

void init_pascal_triangle(int **pascal_triangle,int nrows)
{
	for(int i = 0; i < nrows; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			*(*(pascal_triangle + i) + j) = 1;
		}
	}
}

int** calc_pascal_triangle(int nrows)
{
	int** pascal_triangle = alloc_pascal_triangle(nrows);

	//NULL PTR CHECK

	if(!pascal_triangle) return NULL;

	init_pascal_triangle(pascal_triangle,nrows);

	for(int i = 2; i < nrows; i++)
	{
		for( int j = i-1 ;j > 0; j--)
		{
			 *(*(pascal_triangle + i) + j) = *(*(pascal_triangle + ( i - 1 )) + j) + *(*(pascal_triangle + (i - 1)) + (j - 1));
		}
	}
	return pascal_triangle;
}

void print_pascal_triangle(int **pascal_triangle, int nrows)
{
	for(int i = 0; i < nrows; i++)
	{
		// Alignment of rows
		for(int j = nrows - (i + 1); j > 0; j--)
		{
			printf(" ");
		}

		//Print row
		for(int k = 0; k < (i + 1); k++)
		{
			printf("%6d ",*(*(pascal_triangle + i) + k));
		}
	printf("\n");
}	}



int main()
{

	int nrows;
	printf("Enter the no.of rows: ");
	scanf("%d",&nrows);
	int **pascal_triangle = calc_pascal_triangle(nrows);

	//NULL PTR CHECK
	if(!pascal_triangle)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	print_pascal_triangle(pascal_triangle,nrows);
	free_pascal_triangle(&pascal_triangle,nrows);
	exit(EXIT_SUCCESS);
}
