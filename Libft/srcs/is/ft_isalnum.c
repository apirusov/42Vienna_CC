/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:25:57 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 21:21:56 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
isalnum()
	checks  for  an  alphanumeric character; it is equivalent to (isal‐
    pha(c) || isdigit(c)).
*/
#include "libft.h"

int	ft_isalnum(int a)
{
	if (ft_islower(a) || ft_isupper(a) || ft_isdigit(a))
		return (8);
	return (0);
}
