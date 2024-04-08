/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:16:17 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:12:21 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_putstr_fd
PROTOTYPE
	void ft_putstr_fd(char *s, int fd);
PARAMETERS
	s: The string to output.
	fd: The file descriptor on which to write.
DESCRIPTION
	Outputs the string ’s’ to the given file descriptor.
RETURN VALUE
	None
*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
