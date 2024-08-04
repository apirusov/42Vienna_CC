/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:06:31 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 14:39:24 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!*dst)
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(b, a);
	if (!checker)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(a, b);
	if (!checker)
		ft_printf("pb\n");
}
