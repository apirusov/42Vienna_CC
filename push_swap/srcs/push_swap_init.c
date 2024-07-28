/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:06:39 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 14:44:22 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value
				&& current->value < best_match_value)
			{
				best_match_value = current->value;
				target = current;
			}
			current = current->next;
		}
		if (best_match_value == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	ssize_t	len_a;
	ssize_t	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (!b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
