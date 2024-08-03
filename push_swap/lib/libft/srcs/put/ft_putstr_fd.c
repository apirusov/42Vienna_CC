/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:16:17 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/10 16:53:05 by apirusov         ###   ########.fr       */
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
#include "../../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}
