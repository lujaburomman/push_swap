/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:34:31 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:56:36 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Main function to check and validate input
t_stack	*check_input(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (NULL);
	stack = parse_input(argc, argv);
	validate_input(stack);
	return (stack);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = check_input(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (1);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
