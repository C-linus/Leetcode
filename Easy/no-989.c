/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {

    int* sum = (int *)malloc(sizeof(int) * (numSize + 5));
    int carry = k;
    int i = numSize - 1;
    int digit_len = 0;

    while(i >= 0 || carry > 0)
    {
        if(i >= 0)
        {
            carry += *(num + i);
            i--;
        }

        *(sum + digit_len) = carry % 10;
        digit_len++;
        carry /= 10;
    }

    int temp;

    for(int i = 0; i < digit_len / 2; i++)
    {
        temp = *(sum + i);
        *(sum + i) = *(sum + digit_len - i - 1);
        *(sum + digit_len - i - 1) = temp;
    }

    *returnSize = digit_len;
    return sum;

}
