/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
   *returnSize = strlen(s) + 1;
   int* result = (int *)malloc(sizeof(int) * (*returnSize));
   int low = 0;
   int high = *returnSize - 1;
   int i = 0;
   for(; i < *returnSize - 1; i++)
   {
    if(*(s + i) == 'D')
       *(result + i) = high--;
    else
       *(result + i) = low++;
   }

   *(result + i) = high;
   return result;



}
