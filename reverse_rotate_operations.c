/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:32 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:49:37 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//reverse rotate operations
void	rra(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*tail;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	prev = NULL;
	tail = *stack_a;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	tail->next = *stack_a;
	(*stack_a)->prev = tail;
	*stack_a = tail;
	prev->next = NULL;
	tail->prev = NULL;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rra(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
