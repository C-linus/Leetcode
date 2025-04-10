#define MIN(a,b)((a < b)? a : b)

int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int surface_area = 0;int no_of_cubes;
    for(int rowIndex = 0; rowIndex < gridSize; rowIndex++)
    {
       for(int colIndex = 0; colIndex < *gridColSize; colIndex++)
       {
            no_of_cubes = *(*(grid + rowIndex) + colIndex);

            if(!no_of_cubes) continue;

            surface_area += 6 * no_of_cubes;

            //Top & bottom hidden faces in stacked cubes
            surface_area -= 2 * (no_of_cubes - 1);

            // left & right hidden faces in neighbour cubes of same row
            if(colIndex + 1 < *gridColSize)

               surface_area -= 2 * MIN(no_of_cubes,*(*(grid + rowIndex) + colIndex + 1));

            // front & back hidden faces in neighbour cubes of same column
            if(rowIndex + 1 < gridSize)
                surface_area -= 2 * MIN(no_of_cubes,*(*(grid + rowIndex + 1) + colIndex));
       }
    }
    return surface_area;
}
