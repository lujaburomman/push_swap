#include"push_swap.h"

int stack_size(ft_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int find_min(ft_stack *stack)
{
    int min;
    
    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}