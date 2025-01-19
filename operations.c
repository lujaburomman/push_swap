#include "push_swap.h"

//swap operations
void sa(ft_stack **stack_a)
{
    ft_stack *temp;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;

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

void sb(ft_stack **stack_b)
{
    sa(stack_b);
    ft_printf("sb\n");
}

void ss(ft_stack **stack_a, ft_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    ft_printf("ss\n");
}

//push operations
void pa(ft_stack **stack_a, ft_stack **stack_b)
{
    ft_stack *temp;

    if (!stack_b || !(*stack_b))
        return;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    if(*stack_b)
        (*stack_b)->prev = NULL;
    temp->next = *stack_a;
    if(*stack_a)
        (*stack_a)->prev = temp; 
    *stack_a = temp;
    ft_printf("pa\n");
}

void pb(ft_stack **stack_a, ft_stack **stack_b)
{
    ft_stack *temp;

    if (!stack_a || !(*stack_a))
        return;

    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    if (*stack_a)
        (*stack_a)->prev = NULL;

    temp->next = *stack_b;
    if (*stack_b)
        (*stack_b)->prev = temp;
    *stack_b = temp;

    ft_printf("pb\n");
}

//rotate operations
void ra(ft_stack **stack_a)
{
    ft_stack *temp;
    ft_stack *tail;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;
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

void rb(ft_stack **stack_b)
{
    ra(stack_b);
    ft_printf("rb\n");
}

void rr(ft_stack **stack_a, ft_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    ft_printf("rr\n");
}

//reverse rotate operations
void rra(ft_stack **stack_a)
{
    ft_stack *prev;
    ft_stack *tail;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;

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

void rrb(ft_stack **stack_b)
{
    rra(stack_b);
    ft_printf("rrb\n");
}


void rrr(ft_stack **stack_a, ft_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_printf("rrr\n");
}
