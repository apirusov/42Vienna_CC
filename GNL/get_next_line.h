/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:33:31 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/20 11:33:35 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_list
{
    char			*content;
    struct s_list	*next;
}	t_list;

/*******************************GET NEXT LINE********************************/
char *get_next_line(int fd);
/***********************************BUFFER************************************/
void create_buffer(int fd, t_list **list);
void add_buffer(t_list **list, char *buffer);
/*********************************UTILITIES***********************************/
bool find_newline(t_list *list);
size_t strlen_to_NL(t_list *list);
void my_strcpy(char *next_str, t_list *list);
void ft_free(t_list **list, t_list *clean_node, char *buf);
void clean_list(t_list **list);
t_list	*my_lst_last(t_list *lst);

#endif