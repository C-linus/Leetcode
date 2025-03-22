#define MAX(a,b)((a > b)? a : b)

int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int projections = 0;
    int maxRow;
    int maxCol;

    for(int i = 0; i < gridSize; i++)
    {
        maxRow = 0;
        maxCol = 0;
        for(int j = 0; j < gridSize; j++)
        {
            if(*(*(grid + i) + j) > 0)
               projections++;

            maxRow = MAX(*(*(grid + i) + j),maxRow);
            maxCol = MAX(*(*(grid + j) + i),maxCol);
        }
        projections += (maxRow + maxCol);
    }
    return projections;


}
