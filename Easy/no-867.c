/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = *matrixColSize;
    int **transpose_of_matrix = (int **)malloc(sizeof(int *) * (*returnSize));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*matrixColSize));

    for(int i = 0; i < *returnSize; i++)
    {
        *(transpose_of_matrix + i) = (int *)malloc(sizeof(int) * matrixSize);
        *(*(returnColumnSizes) + i) = matrixSize;
    }


    for(int i = 0; i < matrixSize; i++)
    {
      for(int j = 0; j < *matrixColSize; j++)
      {
        *(*(transpose_of_matrix + j) + i) = *(*(matrix + i) + j);
      }
    }

    return transpose_of_matrix;
}
