/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:05:29 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:16:40 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_putchar_fd
PROTOTYPE
	void ft_putchar_fd(char c, int fd);
PARAMETERS
	c: The character to output.
	fd: The file descriptor on which to write.
DESCRIPTION
	Outputs the character ’c’ to the given file descriptor.
RETURN VALUE
	None
*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
