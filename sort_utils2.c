/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:33:45 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:52:11 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int *values, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (values[mid] == target)
			return (mid);
		else if (values[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	assign_indices(t_stack **stack_a, int *values, int size)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		current->index = binary_search(values, size, current->value);
		current = current->next;
	}
}

void	sort_values(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

int	get_max_bits(t_stack **stack)
{
	t_stack		*head;
	int			max;
	int			max_bits;

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
