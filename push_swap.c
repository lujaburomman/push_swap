#include "push_swap.h"
void sort_two(ft_stack **stack) {
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
}

void sort_three(ft_stack **stack) {
    int first = (*stack)->value;
    int second = (*stack)->next->value;
    int third = (*stack)->next->next->value;

    if (first > second && second < third && first < third) // Case: 2, 1, 3
        sa(stack);
    else if (first > second && second > third) // Case: 3, 2, 1
    {
        sa(stack);
        rra(stack);
    }
    else if (first > second && second < third) // Case: 3, 1, 2
        ra(stack);
    else if (first < second && second > third && first < third) // Case: 1, 3, 2
    {
        sa(stack);
        ra(stack);
    }
    else if (first < second && second > third) // Case: 2, 3, 1
        rra(stack);
}

void sort_small_stack(ft_stack **stack_a, ft_stack **stack_b) {
    int size = 0;
    ft_stack *temp = *stack_a;

    while (temp) {
        size++;
        temp = temp->next;
    }

    while (size > 3) {
        int min_index = find_min_index(*stack_a);

        // Move the minimum element to the top
        if (min_index == 1)
            ra(stack_a);
        else if (min_index == 2)
        {
            ra(stack_a);
            ra(stack_a);
        }
        else if (min_index == 3)
            rra(stack_a);

        pb(stack_b, stack_a); // Push the smallest element to stack B
        size--;
    }
    sort_three(stack_a); // Sort the remaining 3 elements
    while (*stack_b) {
        pa(stack_a, stack_b); // Push everything back to stack A
    }
}

int find_min_index(ft_stack *stack) {
    int min = stack->value;
    int index = 0;
    int min_index = 0;

    while (stack) {
        if (stack->value < min) {
            min = stack->value;
            min_index = index;
        }
        stack = stack->next;
        index++;
    }
    return (min_index);
}


