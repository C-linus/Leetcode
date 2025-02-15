#include <stdio.h>
#include <stdlib.h>


int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *(gridColSize + i); j++) {
            if (*(*(grid + i) + j)) { // Land cell found
                perimeter += 4;

                // Top
                if (i > 0 && *(*(grid + i - 1) + j))
                    perimeter--;

                // Bottom
                if (i < (gridSize - 1) && *(*(grid + i + 1) + j))
                    perimeter--;

                // Left
                if (j > 0 && *(*(grid + i) + j - 1))
                    perimeter--;

                // Right
                if (j < (*(gridColSize + i) - 1) && *(*(grid + i) + j + 1))
                    perimeter--;
            }
        }
    }
    return perimeter;
}



int main() {
    int gridData[4][4] = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int gridSize = 4;
    int gridColSize[4] = {4,4,4,4};

    int** grid = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        grid[i] = (int*)malloc(gridColSize[i] * sizeof(int));
        for (int j = 0; j < gridColSize[i]; j++) {
            grid[i][j] = gridData[i][j];
        }
    }

    int result = islandPerimeter(grid, gridSize, gridColSize);
    printf("The perimeter of the island is: %d\n", result);

    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

