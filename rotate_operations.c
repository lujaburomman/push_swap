/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:22 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:49:24 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//rotate operations
void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*tail;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	tail = *stack_a;
	while (tail->next)
		tail = tail->next;
	tail->next = temp;
	temp->prev = tail;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	ra(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
