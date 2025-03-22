/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int left = 0;
    int temp;

    for(int right = 0; right < numsSize ; right++)
    {
        if(*(nums + right) % 2 == 0)
        {
            temp = *(nums + left);
            *(nums + left) = *(nums + right);
            *(nums + right) = temp;
            left++;
        }
    }
    return nums;

}
