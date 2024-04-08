/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:37:42 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:05:20 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_strjoin
PROTOTYPE
	char *ft_strjoin(char const *s1, char const *s2);
PARAMETERS
	s1: The prefix string.
	s2: The suffix string.
DESCRIPTION
	Allocates (with malloc(3)) and returns a new string, which is the
	result of the concatenation of ’s1’ and ’s2’.
RETURN VALUE
	The new string.
	NULL if the allocation fails.
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
	{
		res = NULL;
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
/*
int main(int ac, char **av)
{
	if(ac != 3)
		return (1);
	printf("%s\n", ft_strjoin(av[1], av[2]));
	return (0);
}*/
