/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:02:28 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:08:01 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
	puterror()  writes  the string s to stream, with error index without its 
	terminating null byte ('\0').
*/
#include "libft.h"

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (2, &str[i], 1);
		i++;
	}
}
/*
int main(void)
{
	ft_puterror("'ft_memmove' will always overflow;");
	return (0);
}*/
