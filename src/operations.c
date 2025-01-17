#include "push_swap.h"

//swap operations
void sa(ft_stack **stack_a)
{
    ft_stack *temp;
    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;
    temp = (*stack_a)->next;
    (*stack_a)->next = temp ->next;
    temp->prev = (*stack_a)->prev;
    (*stack_a)->prev=temp;
    temp->next = *stack_a;
    if(temp->next)
        temp->next->prev = *stack_a;
    *stack_a = temp;
}

void sb(ft_stack **stack_b)
{
    sa(stack_b);
}

void ss(ft_stack **stack_a, ft_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
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
}

void pb(ft_stack **stack_b, ft_stack **stack_a)
{
    pa(stack_b, stack_a);
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
}

void rb(ft_stack **stack_b)
{
    ra(stack_b);
}

void rr(ft_stack **stack_a, ft_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
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

    while (tail->next) {
        prev = tail;
        tail = tail->next;
    }
    tail->next = *stack_a;
    (*stack_a)->prev = tail;
    *stack_a = tail;
    prev->next = NULL;
    tail ->next = NULL;
}

void rrb(ft_stack **stack_b)
{
    rra(stack_b);
}


void rrr(ft_stack **stack_a, ft_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
