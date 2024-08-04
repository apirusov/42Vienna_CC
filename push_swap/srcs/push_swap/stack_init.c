/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:06:50 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 14:26:07 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_init(t_stack_node **a, char **av, bool ac_2)
{
	long	value_to_pass;
	ssize_t	i;

	i = -1;
	while (av[++i])
	{
		if (error_syntax(av[i]))
			ft_free_error(a, av, ac_2);
		value_to_pass = ft_atol(av[i]);
		if (value_to_pass > INT_MAX || value_to_pass < INT_MIN)
			ft_free_error(a, av, ac_2);
		if (error_duplicate(*a, (int)value_to_pass))
			ft_free_error(a, av, ac_2);
		append_node(a, (int) value_to_pass);
	}
}
