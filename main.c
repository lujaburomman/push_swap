#include <stdio.h>
#include "push_swap.h"

void print_stack(ft_stack *stack) {
    while (stack) {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv) {
    ft_stack *stack_a = check_input(argc, argv);

    printf("Parsed Stack:\n");
    print_stack(stack_a);

    free_stack(stack_a);
    return 0;
}
