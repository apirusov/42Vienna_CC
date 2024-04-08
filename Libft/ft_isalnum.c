/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:25:57 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:30:07 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
isalnum()
	checks  for  an  alphanumeric character; it is equivalent to (isal‐
    pha(c) || isdigit(c)).
*/
#include "libft.h"

int	ft_isalnum(char a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || \
		(a >= 48 && a <= 57))
		return (1);
	return (0);
}
