#include "push_swap.h"

/*
    Function to check overflows while converting string into long int
*/

static long ft_atol(const char *str)
{
    long num;
    short isneg;
    int i;

    num = 0;
    isneg = 1;
    i = 0; 
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    num *= isneg;
    return (num);
}

/* 
    Create the stack with command line values
    Checks are emvedded in the creation itself
        ~Duplicate values
        ~Over|Underflow
        ~Syntax errors

    Flag is useful because if it's true, i have the av in the HEAP to free
*/

void stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
    long num;
    int i;

    i = 0;
    while (av[i])
    {
        if (error_syntax(av[i]))
            error_free(a, av, flag_ac_2);
        num = ft_atol(av[i]);
        if (num > INT_MAX || num < INT_MIN)
            error_free(a, av, flag_ac_2);
        if (error_repetition(*a, (int)num))
            error_free(a, av, flag_ac_2);
        append_node(a, (int) num);
        i++;        
    }
    if (flag_ac_2)
        free_matrix(av);
}