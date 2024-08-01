/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:43:49 by apirusov          #+#    #+#             */
/*   Updated: 2024/08/01 21:43:50 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long ft_atol(const char *str)
{
    long num;
    short isneg;
    int i;

    num = 0;
    isneg = 1;
    i = 0; 
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    num *= isneg;
    return (num);
}
