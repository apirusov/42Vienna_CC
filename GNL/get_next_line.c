/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:30:40 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/20 11:30:46 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
    get_next_line
PROTOTYPE
    char *get_next_line(int fd);
PARAMETERS
    fd: The file descriptor to read from
DESCRIPTION
    Write a function that returns a line read from a file descriptor.
    Repeated calls (e.g., using a loop) to your get_next_line() function should
    let you read the text file pointed to by the file descriptor, one line at a 
    time.
    Make sure that your function works as expected both when reading a file and
    when reading from the standard input.
RETURN VALUES
    Your function should return the line that was read.
    If there is nothing else to read or if an error occurred, it should return 
    NULL.
    Returned line should include the terminating \n character, except if the 
    end of file was reached and does not end with a \n.
character.
*/

#include "get_next_line.h"

void clean_list(t_list **list)
{
    t_list *last;
    t_list *clean_node;
    int i;
    int j;
    char *buffer;

    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (!buffer || !clean_node)
        return ;
    last = my_lst_last(*list);
    i = 0; 
    j = 0;
    while (last->content[i] && last->content[i] != '\n')
        i++;
    while (!last->content[i] && last->content[++i])
        buffer[j++] = last->content[i];
    buffer[j] = '\0';
    clean_node->content = buffer;
    clean_node->next = NULL;
    ft_free(list, clean_node, buffer);
}

char *get_line(t_list *list)
{
   size_t  strlen;
   char *next_str;

   if (!list)
       return (NULL);
    strlen = strlen_to_NL(list);
    next_str = (char *)malloc((sizeof(char) * strlen) + 1);
    if (!next_str)
        return (NULL);
    my_strcpy(next_str, list);
    return (next_str);
}

void add_buffer(t_list **list, char *buffer)
{
    t_list *new_node;
    t_list *last;

    last = my_lst_last(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (!last)
        *list = new_node;
    else
        last->next = new_node;
    new_node->content = buffer;
    new_node->next = NULL;
}

void create_buffer(int fd, t_list **list)
{
    size_t char_read;
    char *buffer;

    while (!find_newline(list[fd]))
    {
        buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buffer)
            return ;
        char_read = read(fd, buffer, BUFFER_SIZE);
        if (!char_read)
        {
            free(buffer);
            return ;
        }
        //if (!(char_read == BUFFER_SIZE))
        buffer[char_read] = '\0';
        add_buffer(list, buffer);
    }
}

char *get_next_line(int fd)
{
    static t_list *list;
    char *next_line;

    list = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0) // || read(fd, next_line, 0) < 0)
        return (NULL);
    create_buffer(fd, &list);
    if (!list)
        return (NULL);
    next_line = get_line(list);
    /*bytes_read = read(fd, next_line, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (NULL);*/
    clean_list(&list);
    return (next_line);
}
