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

#define RST "\033[0m"
#define O   "\033[1;33m"  // BOLD Yellow
#define R   "\033[1;31m"  // BOLD Red
#define G   "\033[1;32m"  // BOLD Green
#define Y   "\033[1;33m"  // BOLD Yellow
#define B   "\033[1;34m"  // BOLD Blue
#define M   "\033[1;35m"  // BOLD Magenta

int main ()
{
    int fd;
    char *line;
    //int lines = 1;

    printf (R"Test 1: test.txt \n"RST);
    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("fd-> %d: %s\n", fd, line);
    //close(fd);
    printf (R"Test 2: get_next_line.h \n"RST);
    fd = open("get_next_line.h", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("fd-> %d: %s\n", fd, line);
    //close(fd);
    printf (R"Test 3: lorem.txt \n"RST);
    fd = open("lorem.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("fd-> %d: %s\n", fd, line);
    //close(fd);
    printf (R"Test 4: ten_thousand_no_nl.txt \n"RST);
    fd = open("ten_thousand_no_nl.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("fd-> %d: %s\n", fd, line);
    fd = open("null_followed_by_nl.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("fd-> %d: %s\n", fd, line);
    return (0);
}
