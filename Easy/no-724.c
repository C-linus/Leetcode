#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int* nums, int numsSize) {
    int* leftSum = (int *)malloc(sizeof(int) * numsSize);
    int* rightSum = (int *)malloc(sizeof(int) * numsSize);

    // Left sum of index i
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        sum += *(nums + i);
        *(leftSum + i) = sum;
    }

    // Right sum of index i
    sum = 0;
    for(int i = (numsSize - 1); i > -1; i--)
    {
       sum += *(nums + i);
       *(rightSum + i) = sum;
    }

    int index;
    for(index = 0; index < numsSize; index++)
    {
        if(*(leftSum + index) == *(rightSum + index))
            break;
    }

    free(leftSum);
    free(rightSum);

    return (index == numsSize) ? -1 : index;

}


int main()
{
	int nums[] = {1,7,3,6,5,6};
	int numsSize = sizeof(nums) / sizeof(int);
	printf("The pivot index is :%d\n",pivotIndex(nums,numsSize));
	return EXIT_SUCCESS;
}

