/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:37:41 by laburomm          #+#    #+#             */
/*   Updated: 2025/01/21 13:41:49 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ftprintf/includes/ft_printf.h"
# include "./libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				print_stack(t_stack *stack);

//for inputs
void				error_exit(void);
void				validate_input(t_stack *stack);
t_stack				*parse_input(int argc, char **argv);
t_stack				*add_to_stack(t_stack *stack, int value);
t_stack				*check_input(int argc, char **argv);
int					is_valid_number(char *s);
int					is_within_int_range(char *s);
int					check_duplicates(t_stack *stack);
void				free_stack(t_stack *stack);

//stack operations
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

//implementation of the algorithm
void				sort_two(t_stack **stack_a);
void				sort_three(t_stack **stack_a);
void				sort_four_or_five(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);

//the main sorting function
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

//helper functions for the sorting
int					stack_size(t_stack *stack);
int					find_min(t_stack *stack);
int					find_index(t_stack *stack, int value);
int					*store_original_values(t_stack *stack, int size);
void				convert_to_indices(t_stack **stack_a, int *values);
void				restore_original_values(t_stack **stack_a, int *values);

// Radix sort helper functions
int					get_max_bits(t_stack **stack);
void				sort_values(int *values, int size);
void				assign_indices(t_stack **stack_a, int *values, int size);

#endif
