/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:49:46 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:13:36 by apirusov         ###   ########.fr       */
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
#include "libft.h"

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
