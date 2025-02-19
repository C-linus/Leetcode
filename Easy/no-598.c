#include <stdio.h>

int min(int a,int b)
{
    return (a < b) ? a : b;
}


int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int min_row = m;
    int min_col = n;


    for(int i = 0; i < opsSize; i++)
    {
            min_row = min(min_row,**(ops + i));
            min_col = min(min_col,*(*(ops + i) + 1));
    }
    return min_row * min_col;

}
