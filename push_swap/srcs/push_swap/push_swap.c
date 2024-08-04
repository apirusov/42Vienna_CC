/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:07:06 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 14:16:28 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, (cheapest_node->target_node), 'a');
	pa(a, b, false);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	ssize_t			len;

	len = stack_size(*a);
	if (len == 5 && !stack_sorted(*a))
		sort_five(a, b);
	else
	{
		while (len-- > 3 && !stack_sorted(*a))
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_index(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (ft_puterror("Error\n"), EXIT_FAILURE);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		return (ft_puterror("Error\n"), EXIT_FAILURE);
	stack_init(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	exit(EXIT_SUCCESS);
}