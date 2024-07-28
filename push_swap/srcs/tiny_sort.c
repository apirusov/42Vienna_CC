/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:07:00 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 14:48:24 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, false);
	else if (highest->index == 1)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
