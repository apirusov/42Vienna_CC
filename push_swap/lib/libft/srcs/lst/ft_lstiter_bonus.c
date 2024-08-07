/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:42:59 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 13:18:18 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_lstiter	
PROTOTYPE
	void ft_lstiter(t_list *lst, void (*f)(void *));
PARAMETERS
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.
DESCRIPTION
	Iterates the list ’lst’ and applies the function ’f’ on the content of 
	each node.
RETURN VALUE
	None
*/
#include "../../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
