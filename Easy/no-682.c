#include <stdbool.h>
#include <string.h>

typedef struct stack{
    int* arr;
    int  esp;
    int  size;
} Stack;

bool is_full(Stack* stack)
{
    return (stack->esp == (stack->size - 1)) ? true : false;
}

bool is_empty(Stack* stack)
{
    return (stack->esp == -1) ? true : false;
}

Stack* init_stack(int size)
{
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(sizeof(int) * size);
    stack->esp = -1;
    stack->size = size;
    return stack;
}



void push(Stack* stack,int value)
{
    if(!is_full(stack))
       stack->arr[++stack->esp] = value;

}

int pop(Stack* stack)
{
    if(!is_empty(stack))
        return stack->arr[stack->esp--];
    return 0;
}

void free_stack(Stack** stack)
{
    free((*stack)->arr);
    free(*stack);
    *stack = NULL;
}


int calPoints(char** operations, int operationsSize)
{
    Stack* stack = init_stack(operationsSize);
    int total = 0;

    for(int i = 0; i < operationsSize; i++)
    {
        if(!strcmp(*(operations + i),"C"))
            total -= pop(stack);
        else if(!strcmp(*(operations + i),"D"))
        {
            push(stack,2 * stack->arr[stack->esp]);
            total += stack->arr[stack->esp];
        }
        else if(!strcmp(*(operations + i),"+"))
        {
           push(stack,stack->arr[stack->esp] + stack->arr[stack->esp - 1]);
           total += stack->arr[stack->esp];
        }
        else
        {
            push(stack,atoi(*(operations + i)));
            total += stack->arr[stack->esp];
        }
    }
    free_stack(&stack);

    return total;

}
