/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:01:58 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:15:49 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_lstadd_front	
PROTOTYPE
	void ft_lstadd_front(t_list **lst, t_list *new);
PARAMETERS
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be added to the list.
DESCRIPTION
	Adds the node ’new’ at the beginning of the list.
RETURN VALUE
	None
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
