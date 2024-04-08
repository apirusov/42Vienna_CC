/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:53:29 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:10:26 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_lstmap	
PROTOTYPE
	t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
PARAMETERS
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.
	del: The address of the function used to delete the content of a node 
	if needed.
DESCRIPTION
	Iterates the list ’lst’ and applies the function ’f’ on the content of each 
	node. Creates a new list resulting of the successive applications of the 
	function ’f’. The ’del’ function is used to delete the content of a node 
	if needed. 
RETURN VALUE
	The new list.
	NULL if the allocation fails.
*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	res = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, temp);
		lst = lst->next;
	}
	return (res);
}
