/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:51:12 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:17:10 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_striteri
PROTOTYPE
	void ft_striteri(char *s, void (*f)(unsigned int, char*));	
PARAMETERS
	s: The string on which to iterate.
	f: The function to apply to each character.
DESCRIPTION
	Applies the function ’f’ on each character of the string passed as 
	argument, passing its index as first argument. Each character is passed 
	by address to ’f’ to be modified if necessary.
RETURN VALUE
	None
*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
		while (*s)
			f(i++, s++);
}
