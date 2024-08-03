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

/* 
    Create the stack with command line values
    Checks are emvedded in the creation itself
        ~Duplicate values
        ~Over|Underflow
        ~Syntax errors

    Flag is useful because if it's true, i have the av in the HEAP to free
*/

void	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	num;
	ssize_t	i;

	i = -1;
	while (av[++i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac_2);
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_free(a, av, flag_ac_2);
		if (error_repetition(*a, (int)num))
			error_free(a, av, flag_ac_2);
		append_node(a, (int) num);
	}
	if (flag_ac_2)
		free_matrix(av);
}
