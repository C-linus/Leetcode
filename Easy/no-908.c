#define MAX(a,b)((a > b)?a:b)
#define MIN(a,b)((a < b)?a:b)


int smallestRangeI(int* nums, int numsSize, int k) {

    int minimum, maximum;
    minimum = *nums;
    maximum = *nums;

    for(int i = 0; i < numsSize; i++)
    {
        minimum = MIN(*(nums + i),minimum);
        maximum = MAX(*(nums + i),maximum);
    }

    minimum += k;
    maximum -= k;

    return MAX(0, maximum - minimum );
}
