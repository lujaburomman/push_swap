/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:56:57 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:58:16 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//exits the program whenever there is an error, with a msg
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

//function to add a new node to the stack
t_stack	*add_to_stack(t_stack *stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error_exit();
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (stack == NULL)
	{
		return (new_node);
	}
	else
	{
		current = stack;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
		return (stack);
	}
}

//to free stack
void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
