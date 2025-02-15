#include <stdio.h>
#include <stdlib.h>


int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_soFar = 0;int curr_max = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(!(*(nums + i)))
        {
            max_soFar = (max_soFar > curr_max)? max_soFar : curr_max;
            curr_max = 0;
        }
        else
        {
            curr_max++;
        }
    }
    return (max_soFar > curr_max) ? max_soFar : curr_max;
}



int main()
{

	int nums[] = {1,1,0,1,1,1};
	int numsSize = sizeof(nums) / sizeof(int);
	printf("The maximum consecutive 1's are:%d\n",findMaxConsecutiveOnes(nums,numsSize));
	return EXIT_SUCCESS;
}
