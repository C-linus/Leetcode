#include <stdio.h>
#include <stdlib.h>


/*

*Note: The returned array must be malloced, assume caller calls free().

*/

#define ABS(N) (N > 0) ? N: N * -1


int* findErrorNums(int* nums, int numsSize, int* returnSize) 
{

	int* result = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	int index;

	for(int i = 0; i < numsSize; i++)
	{

		index = ABS(*(nums + i));
		if(*(nums + index - 1) < 0)
			*result = index;

		else
			*(nums + index - 1) = *(nums + index - 1) * -1;

	}

	for(int i = 0; i < numsSize; i++)
	{

		if(*(nums + i) > 0)
		{
			*(result + 1) = i + 1;
			break;

		}

	}
	return result;

}


int main()
{
	int nums[] = {1,2,2,4};
	int numsSize = sizeof(nums) / sizeof(int);
	int returnSize = 0;
	int* result = findErrorNums(nums,numsSize,&returnSize);
	printf("[%d,%d]\n",*result,*(result + 1));
	free(result);
	return EXIT_SUCCESS;
}
