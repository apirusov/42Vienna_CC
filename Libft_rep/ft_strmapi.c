/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:28:42 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:15:11 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_strmapi	
PROTOTYPE
	char *ft_strmapi(char const *s, char (*f)(unsigned int, char));	
PARAMETERS
	s: The string on which to iterate.
	f: The function to apply to each character.
DESCRIPTION
	Applies the function ’f’ to each character of the string ’s’, and passing 
	its index as first argument to create a new string (with malloc(3)) 
	resulting from successive applications of ’f’.
RETURN VALUE
	The string created from the successive applications	of ’f’.
	Returns NULL if the allocation fails.
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
	{
		res = NULL;
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
