#define is_even(a)((a % 2 == 0))
#define is_odd(a)((a % 2 != 0))

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int even_ptr = 0;
    int odd_ptr = 1;

    while(even_ptr < numsSize && odd_ptr < numsSize)
    {
        while(even_ptr < numsSize && is_even(*(nums + even_ptr)))
            even_ptr += 2;

        while(odd_ptr < numsSize && is_odd(*(nums + odd_ptr)))
           odd_ptr += 2;

        if(odd_ptr < numsSize && even_ptr < numsSize)
           swap((nums + odd_ptr),(nums + even_ptr));
    }
    return nums;
}




