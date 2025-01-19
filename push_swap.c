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
    int size = stack_size(*stack_a);

    while (size > 3)
    {
        min = find_min(*stack_a);
        while ((*stack_a)->value != min)
        {
            if (find_index(*stack_a, min) <= size / 2)
                ra(stack_a);
            else
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        size--;
    }
    sort_three(stack_a);
    while (*stack_b)
    {
        pa(stack_a, stack_b);
        if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
    }
}

void radix_sort(ft_stack **stack_a, ft_stack **stack_b)
{
    ft_stack *head_a;
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    head_a = *stack_a;
    size = stack_size(head_a);
    max_bits = get_max_bits(stack_a);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            head_a = *stack_a;
            if (((head_a->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (stack_size(*stack_b) != 0)
            pa(stack_a, stack_b);
        i++;
    }
}

void sort_stack(ft_stack **stack_a, ft_stack **stack_b)
{
    int size;
    int *values = NULL;

    size = stack_size(*stack_a);

    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 4 || size == 5)
        sort_four_or_five(stack_a, stack_b);
    else
    {
        values = store_original_values(*stack_a, size);
        convert_to_indices(stack_a, values);
        radix_sort(stack_a, stack_b);
        restore_original_values(stack_a, values);
        free(values);
    }
}