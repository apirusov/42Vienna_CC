/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:44:31 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 13:17:23 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_lstadd_back	
PROTOTYPE
	void ft_lstadd_back(t_list **lst, t_list *new);
PARAMETERS
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be added to the list.
DESCRIPTION
	Adds the node ’new’ at the end of the list.
RETURN VALUE
	None
*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	add = ft_lstlast(*lst);
	add->next = new;
}
