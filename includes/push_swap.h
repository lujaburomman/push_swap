#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"../libft/includes/libft.h"
#include"../ftprintf/includes/ft_printf.h"
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>

typedef struct stack
{
    int value;
    struct stack *next;
    struct stack *prev;
}ft_stack;

//for inputs
void error_exit(void);
void validate_input(ft_stack *stack);
ft_stack *parse_input(int argc, char **argv);
ft_stack *add_to_stack(ft_stack *stack, int value);
ft_stack *check_input(int argc, char **argv);
int is_valid_number(char *s);
int ft_isdigit(char c);
int is_within_int_range(char *s);
int check_duplicates(ft_stack *stack);
void free_stack(ft_stack *stack);

//stack operations
void    sa(ft_stack **stack_a);
void    sb(ft_stack **stack_b);
void    ss(ft_stack **stack_a, ft_stack **stack_b);
void    pa(ft_stack **stack_a, ft_stack **stack_b);
void    pb(ft_stack **stack_b, ft_stack **stack_a);
void    ra(ft_stack **stack_a);
void    rb(ft_stack **stack_b);
void    rr(ft_stack **stack_a, ft_stack **stack_b);
void    rra(ft_stack **stack_a);
void    rrb(ft_stack **stack_b);
void    rrr(ft_stack **stack_a, ft_stack **stack_b);

//implementation of the algorithm
void    sort_small_stack(ft_stack **stack_a, ft_stack **stack_b);
void    sort_three(ft_stack **stack_a);
int     find_min_index(ft_stack *stack);

#endif