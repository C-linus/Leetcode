bool is_sorted_asc(int* nums, int numsSize){
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(*(nums + i) > *(nums + i + 1))
            return false;
    }
    return true;
}

bool is_sorted_desc(int* nums, int numsSize)
{
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(*(nums + i) < *(nums + i + 1))
            return false;
    }
    return true;
}

bool isMonotonic(int* nums, int numsSize) {
    return is_sorted_asc(nums ,numsSize) || is_sorted_desc(nums,numsSize);

}
