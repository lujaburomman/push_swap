#include "push_swap.h"

void sort_two(ft_stack **stack_a)
{
    if((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void sort_three(ft_stack **stack_a)
{
    int top;
    int mid;
    int bottom ;


    top = (*stack_a)->value;
    mid = (*stack_a)->next->value;
    bottom = (*stack_a)->next->next->value;
    if (top > mid && mid < bottom && top < bottom)
        sa(stack_a);
    else if (top > mid && mid > bottom)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (top > mid && mid < bottom && top > bottom)
        ra(stack_a);
    else if (top < mid && mid > bottom && top < bottom)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (top < mid && mid > bottom && top > bottom)
        rra(stack_a);
}

void sort_four_or_five(ft_stack **stack_a, ft_stack **stack_b)
{
    int min;

    while (stack_size(*stack_a) > 3)
    {
        min = find_min(*stack_a);
        while ((*stack_a)->value != min)
            ra(stack_a);
        pb(stack_a, stack_b);
    }

    sort_three(stack_a);

    while (*stack_b)
        pa(stack_a, stack_b);
}

void radix_sort(ft_stack **stack_a, ft_stack **stack_b)
{
    int max_bits;
    int size;
    int i;
    int j;

    size = stack_size(*stack_a);
    max_bits = 0;
    while ((size >> max_bits) != 0)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*stack_a)->value >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}

void sort_stack(ft_stack **stack_a, ft_stack **stack_b)
{
    int size;
    
    size = stack_size(*stack_a);
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 4 || size == 5)
        sort_four_or_five(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}