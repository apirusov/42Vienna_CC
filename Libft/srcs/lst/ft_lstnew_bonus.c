/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:47:34 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 13:17:09 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_lstnew	
PROTOTYPE
	t_list *ft_lstnew(void *content);
PARAMETERS
	content: The content to create the node with.
DESCRIPTION
	
RETURN VALUE
	Allocates (with malloc(3)) and returns a new node. The member variable
   	’content’ is initialized with the value of the parameter ’content’.
   	The variable ’next’ is initialized to NULL.
*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		new = NULL;
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
