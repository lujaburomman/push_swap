/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:34:17 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:50:21 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap operations
void	sa(t_stack **stack_a)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	if (temp->next)
		temp->next->prev = *stack_a;
	temp->prev = (*stack_a)->prev;
	(*stack_a)->prev = temp;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	sa(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
