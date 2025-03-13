#define MIN(a,b)((a < b) ? a : b)

int minCostClimbingStairs(int* cost, int costSize)
{
    int* minCost = (int *)calloc(costSize + 1,sizeof(int));
    for(int i = 2;i <= costSize; i++)
    {
        *(minCost + i) = MIN((*(cost + i - 1) + *(minCost + i - 1)),(*(cost + i - 2) + *(minCost + i - 2)));
    }
    int min = *(minCost + costSize);
    free(minCost);
    return min;
}



