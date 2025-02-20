#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
	if(n == 0)
		return true;

	if(flowerbedSize == 1)
		return (bool) !(*flowerbed);

    	if(*(flowerbed) == 0 && *(flowerbed + 1) == 0)
    	{
        	*(flowerbed) = 1;
        	n--;
    	}

    	if(*(flowerbed + flowerbedSize - 1) == 0 && *(flowerbed + flowerbedSize - 2)==0)
    	{
        	*(flowerbed + flowerbedSize - 1) = 1;
        	n--;
    	}

   	 for (int i = 1;i < flowerbedSize - 2; i++)
    	{
        	if(*(flowerbed + i) == 0 && *(flowerbed + i - 1) == 0 && *(flowerbed + i + 1) == 0)
        	{
            		*(flowerbed + i) = 1;
            		n--;
        	}
    	}

    	return (n <= 0) ?  true : false;

}

