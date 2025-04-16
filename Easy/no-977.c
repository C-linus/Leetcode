/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;
    int* result = (int *)malloc(sizeof(int) * numsSize);
    int left = 0;
    int right = numsSize - 1;
    int l_val,r_val;

    for(int i = 0; i < numsSize; i++)
        *(nums + i) *= *(nums + i);


    for(int i = numsSize - 1; i >= 0; i--)
    {
        l_val = *(nums + left);
        r_val = *(nums + right);

        if(l_val > r_val)
        {
            *(result + i) = l_val;
            left++;
        }
        else
        {
            *(result + i) = r_val;
            right--;
        }
    }

    return result;

}
