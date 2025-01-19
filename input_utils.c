#include "push_swap.h"

//exits the program whenever there is an error, with a msg
void error_exit(void)
{
    write (2, "Error\n", 6);
    exit(1);
}

//checks if each input is valid

int is_valid_number(char *s)
{
    int i;
    i = 0;
    if(s[i] == '+' || s[i] == '-')
        i++;
    if(!s[i])
        return(0);
    while(s[i])
    {
        if(!ft_isdigit(s[i]))
            return(0);
        i++;
    }
    if(!is_within_int_range(s))
        return(0);
    return(1);
}

// Custom function to check if the number is within the range of INT_MIN to INT_MAX
int is_within_int_range(char *s)
{
    long long value;
    int i;
    int sign;
    
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
//function to add a new node to the stack
ft_stack *add_to_stack(ft_stack *stack, int value)
{
    ft_stack *new_node;
    ft_stack *current;

    new_node = malloc(sizeof(ft_stack));
    if (!new_node)
        error_exit();
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (stack == NULL)
    {
        return new_node;
    }
    else
    {
        current = stack;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
        return stack; 
    }
}

// Parses input arguments and creates the stack
ft_stack *parse_input(int argc, char **argv)
{
    ft_stack *stack;
    int value;
    int i;

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
void validate_input(ft_stack *stack)
{
    if (check_duplicates(stack))
    {
        free_stack(stack);
        error_exit();
    }
}

// Main function to check and validate input
ft_stack *check_input(int argc, char **argv)
{
    ft_stack *stack;

    if (argc < 2)
        return (NULL);

    stack = parse_input(argc, argv);
    validate_input(stack);

    return (stack);
}
//check whether there are dupplicates or not
int check_duplicates(ft_stack *stack)
{
    ft_stack *current;

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