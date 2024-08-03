/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:28:40 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 11:38:05 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_putendl_fd
PROTOTYPE
	void ft_putendl_fd(char *s, int fd);
PARAMETERS
	s: The string to output.
	fd: The file descriptor on which to write.
DESCRIPTION
	Outputs the string ’s’ to the given file descriptor followed by a newline.
RETURN VALUE
	None
*/
#include "../../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
