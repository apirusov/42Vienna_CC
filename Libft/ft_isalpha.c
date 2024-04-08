/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:59:14 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:04:30 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
isalpha()
              checks for an alphabetic character; in the standard "C" locale,  it
              is  equivalent  to  (isupper(c)  ||  islower(c)).  In some locales,
              there may be additional characters for which isalpha() is true—let‐
              ters which are neither uppercase nor lowercase.
*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
/*
int main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_isalpha(*av[1]));
	return (0);
}*/	
