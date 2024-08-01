/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:57:15 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/10 16:52:52 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	fputs()  writes  the string s to stream, without its terminating null byte
       ('\0').
*/
#include "../../includes/libft.h"

void	ft_putstr(char *str)
{
	if (str != NULL)
		ft_putstr_fd(str, 1);
}
/*
int main(void)
{
	ft_putstr("Hello World");
	return (0);
}*/
