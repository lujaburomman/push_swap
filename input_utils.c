/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:32:08 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:58:01 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if each input is valid
int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (!is_within_int_range(s))
		return (0);
	return (1);
}

//function to check if the number is within the range
int	is_within_int_range(char *s)
{
	long long	value;
	int			i;
	int			sign;

	value = 0;
	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		value = value * 10 + (s[i] - '0');
		i++;
		if (value * sign > INT_MAX || value * sign < INT_MIN)
			return (0);
	}
	return (1);
}

//checks all the inputs
// Parses input arguments and creates the stack
t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		value;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			free_stack(stack);
			error_exit();
		}
		value = ft_atoi(argv[i]);
		stack = add_to_stack(stack, value);
		i++;
	}
	return (stack);
}

// Validates the stack, checks for duplicates)
void	validate_input(t_stack *stack)
{
	if (check_duplicates(stack))
	{
		free_stack(stack);
		error_exit();
	}
}

//check whether there are dupplicates or not
int	check_duplicates(t_stack *stack)
{
	t_stack	*current;

	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (current->value == stack->value)
				return (1);
			current = current->next;
		}
		stack = stack->next;
	}
	return (0);
}
