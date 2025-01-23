/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:33:31 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:41:01 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	*store_original_values(t_stack *stack, int size)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * size);
	if (!values)
		error_exit();
	i = 0;
	while (stack)
	{
		values[i++] = stack->value;
		stack = stack->next;
	}
	return (values);
}

void	convert_to_indices(t_stack **stack_a, int *values)
{
	int	size;

	size = stack_size(*stack_a);
	sort_values(values, size);
	assign_indices(stack_a, values, size);
}

void	restore_original_values(t_stack **stack_a, int *values)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		current->value = values[current->index];
		current = current->next;
	}
}
