#include "push_swap.h"

//exits the program whenever there is an error, with a msg
void error_exit(void)
{
    write (2, "Error\n", 6);
    exit(1);
}

//checks if each input is valid
int ft_isdigit(char c)
{
    return(c >= '0' && c <= '9');
}

int is_valid_number(char *s)
{
    int i;
    i = 0;
    if(s[i] == '+' || s[i] == '-')
        i++;
    if(!s)
        return(0);
    while(s[i])
    {
        if(!ft_isdigit(s[i]))
            return(0);
        if(!is_within_int_range(s))
            return(0);
        i++;
    }
     return(1);
}

// Custom function to check if the number is within the range of INT_MIN to INT_MAX
int is_within_int_range(char *s)
{
    long long value;
    int i;
    int sign;
    int min;
    int max;
    
    value = 0;
    i = 0;
    sign = 1;
    min = -2147483648;
    max = 2147483647;
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
        if (value * sign > max || value * sign < min)
            return (0);
    }
    return (1);
}

//checks all the inputs
ft_stack *check_input(int argc, char **argv)
{
    ft_stack *stack = NULL;
    ft_stack *new_node;
    int value;
    int i = 1;

    if (argc < 2)
        return (NULL);
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
            error_exit();
        value = ft_atoi(argv[i]);
        new_node = malloc(sizeof(ft_stack));
        if (!new_node)
            error_exit();
        new_node->value = value;
        new_node->next = stack;
        stack = new_node;
        i++;
    }
    if (check_duplicates(stack))
    {
        free_stack(stack);
        error_exit();
    }
    return (stack);
}

//check whether there are dupplicates or not
int check_duplicates(ft_stack *stack) {
    ft_stack *current;

    while (stack) {
        current = stack->next;
        while (current) {
            if (current->value == stack->value)
                return (1);
            current = current->next;
        }
        stack = stack->next;
    }
    return (0);
}


//to free stack
void free_stack(ft_stack *stack)
{
    ft_stack *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}