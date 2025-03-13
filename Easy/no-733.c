/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void fill(int** image,int rowSize, int colSize,int sr, int sc, int color , int newColor)
{
    if(sr < 0 || sc < 0 || sr >= rowSize || sc >= colSize || *(*(image + sr) + sc) != color)
        return;

    *(*(image + sr) + sc) = newColor;

    fill(image,rowSize,colSize,sr - 1,sc,color,newColor);
    fill(image,rowSize,colSize,sr + 1,sc,color,newColor);
    fill(image,rowSize,colSize,sr, sc - 1, color,newColor);
    fill(image,rowSize,colSize,sr,sc + 1, color, newColor);
}


int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    if(*(*(image + sr) + sc) == color) return image;

    fill(image,imageSize,*imageColSize,sr,sc,*(*(image + sr) + sc),color);

    return image;

}
