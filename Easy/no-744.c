#include <stdio.h>
#include <stdlib.h>

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0;
    int right = lettersSize - 1;
    int mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(*(letters + mid) <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left < lettersSize) ? *(letters + left) : *letters;

}


int main()
{
	char letters[] = {'c','f','j'};
	char target = 'a';
	printf("The Smallest letter greater than target:%c\n",nextGreatestLetter(letters,sizeof(letters),target));
	return EXIT_SUCCESS;
}
