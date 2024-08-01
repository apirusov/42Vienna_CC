/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:24:05 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 13:17:53 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_lstlast
PROTOTYPE
	t_list *ft_lstlast(t_list *lst);
PARAMETERS
	lst: The beginning of the list.
DESCRIPTION
	Returns the last node of the list.	
RETURN VALUE
	Last node of the list
*/
#include "../../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
