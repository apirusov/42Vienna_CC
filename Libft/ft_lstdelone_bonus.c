/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:27:37 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 13:18:02 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_lstdelone	
PROTOTYPE
	void ft_lstdelone(t_list *lst, void (*del)(void *));
PARAMETERS
	lst: The node to free.
	del: The address of the function used to delete the content.
DESCRIPTION
	Takes as a parameter a node and frees the memory of the node’s content 
    using the function ’del’ given as a parameter and free the node.
    The memory of ’next’ must not be freed.
RETURN VALUE
	None
*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
/*
int main(void)
{
	int	i;

	i = 0;
	t_list *new[5];
	new[0]->content = "Hello ";
	new[1]->content = "stupid ";
	new[2]->content = "freaking ";
	new[3]->content = "cruel ";
	new[4]->content = "World!";
	ft_lstdelone(*new, (void *)new[4]);
	while (i < 5 && *new)
	{
		printf("%s[%d]\n", (unsigned char *)new[i]->content, i);
	}
	return (0);
}*/
