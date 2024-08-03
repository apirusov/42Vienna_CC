/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:49:46 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 13:17:41 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_lstsize
PROTOTYPE
	int ft_lstsize(t_list *lst);
PARAMETERS
	lst: The beginning of the list.
DESCRIPTION
	Counts the number of nodes in a list.
RETURN VALUE
	The length of the list
*/
#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
