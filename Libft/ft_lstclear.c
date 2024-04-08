/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:53:44 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 20:16:07 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_lstclear	
PROTOTYPE
	void ft_lstclear(t_list **lst, void (*del)(void *));
PARAMETERS
	lst: The address of a pointer to a node.
	del: The address of the function used to delete	the content of the node.
DESCRIPTION
	Deletes and frees the given node and every successor of that node, using 
	the function ’del’ and free(3). 
	Finally, the pointer to the list must be set to NULL.
RETURN VALUE
	None
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
	*lst = 0;
}
