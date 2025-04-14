#include <stdbool.h>
#include <stdlib.h>

bool isAlienSorted(char** words, int wordsSize, char* order) {
    int* alien_order = (int *) malloc(sizeof(int) * 26);
    for(int i = 0; i < strlen(order); i++)
        *(alien_order + *(order + i) - 'a')  = i;
    char* word1 = NULL;
    char* word2 = NULL;
    bool is_valid;
    for(int i = 0; i < wordsSize - 1; i++)
    {
        word1 = *(words + i);
        word2 = *(words + i + 1);
        int j,k;
        j=k=0;
        char letter1,letter2;
        is_valid = true;
        while(true)
        {
            letter1 = *(word1 + j);
            letter2 = *(word2 + k);
            if(letter1 == '\0' || letter2 == '\0')
            {
                if(letter2 == '\0' && letter1 != '\0')
                    is_valid = false;
                break;
            }

            if(letter1 != letter2)
            {
                if(*(alien_order + letter1 - 'a') > *(alien_order + letter2 - 'a'))
                    is_valid = false;
                break;
            }
            j++;
            k++;
        }
        if(!is_valid)
           break;

    }
    if(!is_valid)
    {
        free(alien_order);
        return false;
    }
    return true;
}
