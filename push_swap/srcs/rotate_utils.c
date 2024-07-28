/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:07:31 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 15:01:02 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a,
				t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

void	reverse_rotate_both(t_stack_node **a,
				t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}

void	finish_rotation(t_stack_node **stack,
				t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
