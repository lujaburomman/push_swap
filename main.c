#include <stdio.h>
#include "push_swap.h"

void print_stack(ft_stack *stack)
{
    while (stack)
    {
        ft_printf("%d -> ", stack->value);
        stack = stack->next;
    }
    ft_printf("NULL\n");
}

int main(int argc, char **argv)
{
    ft_stack *stack_a;
    ft_stack *stack_b;

    stack_a = check_input(argc, argv);
    stack_b = NULL;
    if(!stack_a)
        return(1);
    ft_printf("initial Stack:\n");
    print_stack(stack_a);
    sort_stack(&stack_a, &stack_b);
    ft_printf("sorted stack:\n");
    print_stack(stack_a);
    free_stack(stack_a);
    return 0;
}
