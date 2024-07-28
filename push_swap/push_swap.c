#include "push_swap.h"

int main (int ac, char **av)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if (1 == ac || (2 == ac && !av[1][0]))
        return (1);
    else if (2 == ac)
        av = ft_split(av[1], ' ');
    stack_init(&a, av + 1, 2 == ac);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len(a) == 3)
            tiny_sort(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
    
}