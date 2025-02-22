#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)(a > b)? a : b

double findMaxAverage(int* nums, int numsSize, int k) {
    int curr_window_sum = 0;
    for(int i = 0; i < k; i++)
        curr_window_sum += *(nums + i);

    int max_window_sum = curr_window_sum;
    int start_index = 0;
    int end_index = k;
    while(end_index < numsSize)
    {
        curr_window_sum -= *(nums + start_index);
        start_index++;

        curr_window_sum += *(nums + end_index);
        end_index++;

        max_window_sum = MAX(curr_window_sum,max_window_sum);

    }
    return (double)max_window_sum / k;

}



int main()
{
	int nums[] = {1,12,-5,-6,50,3};
	int k = 4;
	int numsSize = sizeof(nums) / sizeof(int);
	printf("The Maximum Average:%lf\n",findMaxAverage(nums,numsSize,k));
	return EXIT_SUCCESS;
}
