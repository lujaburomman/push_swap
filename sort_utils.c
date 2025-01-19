#include"push_swap.h"

int stack_size(ft_stack *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
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

int find_index(ft_stack *stack, int value)
{
    int index;

    index = 0;
    while (stack)
    {
        if (stack->value == value)
            return index;
        stack = stack->next;
        index++;
    }
    return -1;
}

int get_max_bits(ft_stack **stack)
{
    ft_stack *head;
    int max;
    int max_bits;

    head = *stack;
    max = head->index;
    max_bits = 0;
    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

int *store_original_values(ft_stack *stack, int size)
{
    int *values = malloc(sizeof(int) * size);
    if (!values)
        error_exit();
    int i = 0;
    while (stack)
    {
        values[i++] = stack->value;
        stack = stack->next;
    }
    return (values);
}

void convert_to_indices(ft_stack **stack_a, int *values)
{
    int size = stack_size(*stack_a);

    sort_values(values, size);
    assign_indices(stack_a, values, size);
    free(values);
}

void restore_original_values(ft_stack **stack_a, int *values)
{
    ft_stack *current = *stack_a;
    while (current)
    {
        current->value = values[current->index];
        current = current->next;
    }
}

void sort_values(int *values, int size)
{
    int i = 0;
    while (i < size)
    {
        int j = i + 1;
        while (j < size)
        {
            if (values[i] > values[j])
            {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
            j++;
        }
        i++;
    }
}

#include <stdbool.h>

// Binary search to find the index of a value in the sorted array
int binary_search(int *values, int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (values[mid] == target)
            return mid;
        else if (values[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

void assign_indices(ft_stack **stack_a, int *values, int size)
{
    ft_stack *current = *stack_a;
    while (current)
    {
        current->index = binary_search(values, size, current->value);
        current = current->next;
    }
}