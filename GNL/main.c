/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:41:32 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/20 11:41:34 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
    int fd;
    char *line;
    int lines = 1;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("fd-> %d: %s\n", lines++, line);
    close(fd);
    return (0);
}
