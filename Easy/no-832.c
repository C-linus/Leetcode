void reverseArray(int* arr, int size)
{
    int temp;
    for(int i = 0; i < (size / 2); i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }

}

void inverseArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = !(*(arr + i));
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    // Reverse the inner arrays
    for(int i = 0; i < imageSize; i++)
    {
        reverseArray(*(image + i), *imageColSize);
        inverseArray(*(image + i), *imageColSize);
    }

    return image;

}
