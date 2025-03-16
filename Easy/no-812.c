#include <math.h>
#define MAX(a,b)((a > b)? a : b)

typedef struct point
{
    int x;
    int y;
} Point;

double area_of_triangle(Point point1,Point point2,Point point3)
{
    return abs(point1.x * (point2.y - point3.y) + point2.x * (point3.y - point1.y) + point3.x * (point1.y - point2.y)) / 2.0;
}


double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double maxArea = 0.0;
    for(int i = 0; i < pointsSize; i++)
    {
        for(int j = i + 1; j < pointsSize; j++)
        {
            for(int k = j + 1; k < pointsSize; k++)
            {
                double area = area_of_triangle((Point){.x = *(*(points + i)), .y = *(*(points + i) + 1)},(Point){.x = *(*(points + j)), .y = *(*(points + j) + 1)},(Point){.x = *(*(points + k)),*(*(points + k) + 1)});

                maxArea = MAX(area , maxArea);
            }
        }
    }
    return maxArea;
}
