#define MAX_LINE_WIDTH 100
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int* result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int width_of_line = 0;
    int newlines = 1;
    int letter_width;

    for(int i = 0; *(s + i) != '\0' ;i++)
    {
        letter_width = *(widths + (*(s + i) - 'a'));
        if(letter_width + width_of_line > MAX_LINE_WIDTH)
        {
            newlines++;
            width_of_line = 0;
        }
        width_of_line += letter_width;
    }
    *result = newlines;
    *(result + 1) = width_of_line;

    return result;

}
