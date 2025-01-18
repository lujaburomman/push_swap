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
void sort_two(ft_stack **stack_a);
void sort_three(ft_stack **stack_a);
void sort_four_or_five(ft_stack **stack_a, ft_stack **stack_b);
void radix_sort(ft_stack **stack_a, ft_stack **stack_b);

//the main sorting function
void sort_stack(ft_stack **stack_a, ft_stack **stack_b);

//helper functions for the sorting
int stack_size(ft_stack *stack);
int find_min(ft_stack *stack);

#endif