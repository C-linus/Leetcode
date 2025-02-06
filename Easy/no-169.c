#include <stdio.h>
#include <stdlib.h>



int majority_element(int *arr,int size)
{
	int candidate,score;
	candidate = *arr;
	score = 1;
	for (int i = 1; i < size; i++)
	{
		if(score == 0)
			candidate = *(arr + i);

		if(*(arr + i) == candidate)
			score++;
		else
			score--;
	}
	return candidate;
}

int main()
{
	int arr[] ={1,1,1,2,2,2};
	int size = sizeof(arr) / sizeof(int);
	printf("The majority element is:%d\n",majority_element(arr,size));
	return EXIT_SUCCESS;
}
