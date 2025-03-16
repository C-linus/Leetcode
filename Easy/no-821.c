#include <string.h>
#include <math.h>
#define MIN(a,b)((a < b) ? a : b)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    *returnSize = strlen(s);
    int* short_dist_from_char = (int *)malloc(sizeof(int) * (*returnSize));
    int last_seen = -1 * (*returnSize);
    // calucalte distance from left to last_seen of character
    for(int i = 0; i < *returnSize; i++)
    {
        if(*(s + i) == c)
            last_seen = i;
        *(short_dist_from_char + i) = i - last_seen;
    }

    // Calculate distance from min(left, right) of last_seen character
    for(int i = (*returnSize) - 1; i > -1 ; i--)
    {
        if(*(s + i) == c)
            last_seen = i;

        *(short_dist_from_char + i) = MIN(*(short_dist_from_char + i),abs(i - last_seen));
    }
    return short_dist_from_char;

}
