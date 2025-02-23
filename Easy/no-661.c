#include <stdio.h>
#include <stdlib.h>

/*

Return an array of arrays of size *returnSize.

The sizes of the arrays are returned as returnColumnSizes array.

Note: Both returned array and columnSizes array must be malloced, assume caller calls free().

*/

int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int**returnColumnSizes)
{

	*returnSize = imgSize;
	*returnColumnSizes = imgColSize;
	/*
		Lower BYTE -> Original pixel value

		Upper BYTE -> Average of (3 x 3) surrounding grid of that pixel value

	*/

	int total = 0;
	int count = 0;

	for(int row = 0; row < imgSize; row++)
	{

		for(int col=0; col < *imgColSize; col++)
		{

			// Computing Average of that pixel from its surrounding (3 x 3) grid
			total = 0;
			count = 0;
			for(int grid_row = row - 1; grid_row <= row + 1; grid_row++)
			{
				for(int grid_col = col - 1; grid_col <= col + 1; grid_col++)
				{

				// Boundary check

					if((grid_row >= 0 && grid_row< imgSize) && (grid_col >= 0 && grid_col < *imgColSize))
					{

						total += (*(*(img+grid_row) + grid_col) & 0x00FF);
						count++;
					}
				}
			}
			 *(*(img+ row) + col) = *(*(img+row) + col) | ((total / count) << 8);
		}

	}

	for(int row= 0; row < imgSize; row++)
		for(int col=0; col < *imgColSize; col++)
			*(*(img+ row) + col) >>= 8;

	return img;

}


int main()
{
    int imgSize = 3, imgColSize = 3;
    int imgData[3][3] = {
        {100, 200, 100},
        {200, 50,  200},
        {100, 200, 100}
    };

    // Allocate memory for input image as 2D array
    int** img = (int**)malloc(imgSize * sizeof(int*));
    for (int i = 0; i < imgSize; i++) {
        img[i] = (int*)malloc(imgColSize * sizeof(int));
        for (int j = 0; j < imgColSize; j++) {
            img[i][j] = imgData[i][j];
        }
    }

    int returnSize;
    int* returnColumnSizes;
    int** smoothedImg = imageSmoother(img, imgSize, &imgColSize, &returnSize, &returnColumnSizes);

    // Print result
    printf("Smoothed Image:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", smoothedImg[i][j]);
        }
        printf("\n");
    }

   // Free allocated memory
    for (int i = 0; i < imgSize; i++)
        free(smoothedImg[i]);

    free(smoothedImg);

    return 0;
}
