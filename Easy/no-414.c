#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_third_maximum(int* arr,unsigned int length)
{
	int  max1 = *arr;
	long long int  max2 = LLONG_MIN , max3 = LLONG_MIN ;
	int curr;
	for(int i = 1; i < length; i++)
	{
		curr = *(arr + i);
		if(curr > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = curr;
		}
		else if(curr > max2 && curr < max1)
		{
			max3 = max2;
			max2 = curr;
		}
		else if(curr > max3 && curr < max2)
		{
			max3 = curr;
		}

	}
	return (max3 == LLONG_MIN)? max1 : (int) max3;
}

 



int main()
{
	int arr[] = {2,2,3,1};
	unsigned int length = sizeof(arr) / sizeof(int);
	printf("The 3rd maximum number is:%d\n",find_third_maximum(arr,length));
	return EXIT_SUCCESS;
} 
