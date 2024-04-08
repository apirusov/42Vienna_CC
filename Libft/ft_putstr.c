/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:57:15 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/06 13:27:07 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	fputs()  writes  the string s to stream, without its terminating null byte
       ('\0').
*/
#include "libft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
/*
int main(void)
{
	ft_putstr("Hello World");
	return (0);
}*/
