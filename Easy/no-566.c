#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    if(matSize * (*matColSize) != r * c)
    {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    *returnSize = r;

    int** reShape = (int **)malloc(r * sizeof(int *));
    *returnColumnSizes = (int *)malloc(r * sizeof(int));

    for(int i = 0 ; i < r; i++)
    {
        *(reShape + i) = (int *)malloc(c * sizeof(int));
        *((*returnColumnSizes) + i) = c;
    }

    for(int i = 0; i < r * c; i++)
    {
       *(*(reShape + i / c) + i % c) = *(*(mat + i / *matColSize) + i % *matColSize);
    }
    return reShape;

}







