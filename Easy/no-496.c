/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int *arr;
    int esp;
    int size;
} Stack;

Stack* init_stack(int size)
{
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->arr = (int *)malloc(sizeof(int) * size);
    stack->esp = -1;
    return stack;
}

void free_stack(Stack** stack)
{
    free((*stack)->arr);
    free(*stack);
    *stack = NULL;
}

bool is_full(Stack* stack)
{
    return (stack->esp == (stack->size - 1));
}

bool is_empty(Stack* stack)
{
    return stack->esp == -1;
}

void push(Stack* stack,int value)
{
    if(!is_full(stack))
    {
        stack->esp++;
        stack->arr[stack->esp] = value;
    }
}

void pop(Stack* stack)
{
    if(!is_empty(stack))
    {
        stack->esp--;
    }
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
     int* result = (int *)malloc(nums1Size * sizeof(int));
     int* nums2_res = (int *)malloc(nums2Size * sizeof(int));
     *returnSize = nums1Size;

     Stack* stack = init_stack(nums2Size);
     int element;
     for(int i = nums2Size - 1; i >= 0; i--)
    {
        element = nums2[i];
        if(is_empty(stack))
        {
           nums2_res[i] = -1;
           push(stack,element);
           continue;
        }

        if(stack->arr[stack->esp] > nums2[i])
        {
            nums2_res[i] = stack->arr[stack->esp];
            push(stack,element);
            continue;
        }

        while(!is_empty(stack) && (stack->arr[stack->esp] <= nums2[i]))
              pop(stack);

        if(is_empty(stack))

            nums2_res[i] = -1;
        else
            nums2_res[i] = stack->arr[stack->esp];


        push(stack,element);
    }

    free_stack(&stack);

    for(int i = 0; i < nums1Size; i++)
    {
        for(int j = 0; j < nums2Size; j++)
        {
            if(*(nums1 + i) == *(nums2 + j))
            {
                *(result + i) = *(nums2_res + j);
                break;
            }
        }
    }
    free(nums2_res);
    return result;


}

void print_arr(int* arr, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ",*(arr + i));
	printf("\n");
}


int main()
{

	int nums1[] = {4,1,2};
	int nums1Size = sizeof(nums1) / sizeof(int);
	int nums2[] = {1,3,4,2};
	int nums2Size = sizeof(nums2) / sizeof(int);
	int returnSize = 0;
	print_arr(nextGreaterElement(nums1,nums1Size,nums2,nums2Size,&returnSize),returnSize);
	return EXIT_SUCCESS;

}

