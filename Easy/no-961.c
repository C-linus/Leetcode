int repeatedNTimes(int* nums, int numsSize) {
    int num;
    for(int i = 0; i < numsSize; i++)
    {
        num = *(nums + i);
        if(i + 1 < numsSize && num == *(nums + i + 1))
            return num;
        else if(i + 2 < numsSize && num == *(nums + i + 2))
            return num;
        else if(i + 3 < numsSize && num == *(nums + i + 3))
            return num;
    }
    return -1;
}
