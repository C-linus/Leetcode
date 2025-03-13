
int dominantIndex(int* nums, int numsSize)
{
    int maxIndex = 0;

    for(int i = 1; i < numsSize; i++)
    {

       if(*(nums + maxIndex) < *(nums + i))
            maxIndex = i;
    }
    int max = *(nums + maxIndex);
    for(int i = 0; i < numsSize; i++)
    {
        if(i == maxIndex) continue;

        if(2 * (*(nums + i)) > max)
           return -1;
    }
    return maxIndex;
}
