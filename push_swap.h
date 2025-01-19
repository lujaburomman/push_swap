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
    int index;  // Added index field
    struct stack *next;
    struct stack *prev;
} ft_stack;

void print_stack(ft_stack *stack);

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
int find_index(ft_stack *stack, int value);
int *store_original_values(ft_stack *stack, int size);
void convert_to_indices(ft_stack **stack_a, int *values);
void restore_original_values(ft_stack **stack_a, int *values);

// Radix sort helper functions
int get_max_bits(ft_stack **stack);
void sort_values(int *values, int size);
void assign_indices(ft_stack **stack_a, int *values, int size);

#endif