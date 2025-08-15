#include <stdio.h>
#include <stdlib.h>




int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* trust_count = (int *)calloc((n + 1),sizeof(int));

    if(trust_count == NULL)
      exit(1);


    for(int i = 0; i < trustSize; i++)
    {
        *(trust_count + **(trust + i)) -= 1;
        *(trust_count + *(*(trust + i) + 1)) += 1;
    }

    for(int i = 1; i <= n; i++)
    {
        if(*(trust_count + i) == n - 1)
        {
           free(trust_count);
           return i;
        }
    }
    free(trust_count);
    return -1;
}
