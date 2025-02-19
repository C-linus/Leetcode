#include <stdio.h>
#include <stdlib.h>

/// Binary Search
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while(left <= right)
    {
        mid = (left + right) / 2;

        if(*(nums + mid) == target)
            return mid;

        else if(*(nums + mid) > target)
            right = mid - 1;

        else if(*(nums + mid) < target)
            left = mid + 1;
    }
    return -1;
}


int main()
{
	int nums[] = {-1,0,3,5,9,12};
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 9;
	int index = search(nums,numsSize,target);
	if(index == -1)
		printf("The target:%d Not Found\n",target);
	else
		printf("The target:%d Found at index:%d\n",target,index);
	return (index == -1) ? EXIT_FAILURE : EXIT_SUCCESS;
}
