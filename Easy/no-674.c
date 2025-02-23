#include <stdio.h>
#include <stdlib.h>


#define MAX(a,b) (a > b) ? a : b

int findLengthOfLCIS(int* nums, int numsSize) {
    int max = 1;int count = 1;
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(*(nums + i) >= *(nums + i +1))
        {
            max = MAX(max,count);
            count = 1;
        }
        else
        {
            count++;
        }

    }
    return MAX(max,count);
}


int main()
{
	int nums[] = {1,3,5,4,7};
	int numsSize = sizeof(nums) / sizeof(int);
	printf("The length of longest continous increasing subsequence is:%d\n",findLengthOfLCIS(nums,numsSize));
	return EXIT_SUCCESS;
}
