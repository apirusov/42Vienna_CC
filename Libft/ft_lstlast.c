/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:24:05 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:07:02 by apirusov         ###   ########.fr       */
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
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
