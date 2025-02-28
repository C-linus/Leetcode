#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




bool isOneBitCharacter(int* bits, int bitsSize) {
    int index = 0;
    int flag = 0;

    while(index < bitsSize)
    {
        if(*(bits + index) == 1)
        {
            index += 2;
            flag = 2;
        }
        else
        {
            index++;
            flag = 1;
        }
    }

    return (flag == 1) ? true : false;

}

int main()
{
	int bits[] = {1,1,1,0};
	int bitsSize = sizeof(bits) / sizeof(int);
	printf("Array %s with 1-Bit character\n",(isOneBitCharacter(bits,bitsSize))? "ends" : "not ends");
	return EXIT_SUCCESS;
}
