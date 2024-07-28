#include "push_swap.h"
#include <climits>


// Same as ft_lstlast

t_stack_node *find_last_node(t_stack_node *head)
{
    if (NULL == head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

void append_node (t_stack_node **stack, int num)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if (!stack)
        return ;
    node->next = NULL;
    node->value = num;
    if (!*stack)
    {
        *stack = node;
        node->prev = NULL;
    }
    else 
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

t_stack_node *find_smallest(t_stack_node *stack)
{
    long smallest;
    t_stack_node *smallest_node;

    if (!stack)
        return (NULL);
    smallest = LONG_MAX;
    while (stack)
    {
        if (stack->value < smallest)
        {
            smallest = stack->value;
            smallest_node = stack;
        }    
    }
    return (smallest_node);
}

t_stack_node *return_cheapest(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

// Same as lst_size
int stack_len(t_stack_node *stack)
{
    int count;
    
    count = 0;
    while (stack)
    {
        ++count;
        stack = stack->next;
    }
    return (count);
}