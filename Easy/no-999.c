#include <stdio.h>
#include <stdlib.h>







int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    int rook_position_x,rook_position_y;
    int no_of_attacks = 0; // Maximum is 4 ,Minimum is 0
    for(int x = 0; x < boardSize; x++)
    {
        for(int y = 0; y < *boardColSize; y++)
        {
            if(*(*(board + x) + y) == 'R')
            {
                rook_position_x = x;
                rook_position_y = y;
                break;
            }
        }
    }

    //// Vertical attacks

    // Up direction
    for(int x = rook_position_x; x > -1; x--)
    {
        if(*(*(board + x) + rook_position_y) == 'B')
            break;

        else if(*(*(board + x) + rook_position_y) == 'p')
        {
            no_of_attacks++;
            break;
        }
    }

    // Down Direction
    for(int x = rook_position_x; x < boardSize; x++)
    {
        if(*(*(board + x) + rook_position_y) == 'B')
            break;

        else if(*(*(board + x) + rook_position_y) == 'p')
        {
            no_of_attacks++;
            break;
        }
    }

    //// Horizontal Attacks

    // Left Direction
    for(int y = rook_position_y; y > -1; y--)
    {
        if(*(*(board + rook_position_x) + y) == 'B')
            break;

        else if(*(*(board + rook_position_x) + y) == 'p')
        {
            no_of_attacks++;
            break;
        }
    }

    // Right Direction
    for(int y = rook_position_y; y < *boardColSize; y++)
    {
        if(*(*(board + rook_position_x) + y) == 'B')
            break;
        else if(*(*(board + rook_position_x) + y) == 'p')
        {
            no_of_attacks++;
            break;
        }
    }

    return no_of_attacks;
}
