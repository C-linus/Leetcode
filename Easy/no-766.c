#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for(int row = 0; row < matrixSize - 1; row++)
    {
        for(int col = 0; col < *matrixColSize - 1; col++)
        {
            if(*(*(matrix + row) + col) != *(*(matrix + row + 1) + col + 1))
                return false;
        }
    }
    return true;
}


int main()
{	int matrixSize = 3;
	int matrixColSize = 4;
	int** matrix = (int **)malloc(sizeof(int *) * matrixSize);
	for(int i=0; i < matrixSize; i++)
		*(matrix + i) = (int *)malloc(sizeof(int) * matrixColSize);
	printf("%s\n",(isToeplitzMatrix(matrix,matrixSize,&matrixColSize))? "Toeplitz Matrix" : "Not A Toeplitz Matrix");
	return EXIT_SUCCESS;
}
