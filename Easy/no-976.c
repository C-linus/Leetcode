int compare(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int largestPerimeter(int* nums, int numsSize) {

    qsort(nums,numsSize,sizeof(int),compare);
    int l1,l2,l3;
    for(int i = numsSize - 1; i >= 2; i--)
    {
        l1 = *(nums + i - 2);
        l2 = *(nums + i - 1);
        l3 = *(nums + i);
        if(l3 < l2 + l1)
            return l3 + l2 + l1;
    }

    return 0;

}
