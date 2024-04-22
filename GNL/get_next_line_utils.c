/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:41:24 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/20 11:41:27 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool find_newline(t_list *list)
{
    size_t i;

    if (!list)
        return (false);
    while (list)
    {
        i = 0;
        while (list->content[i] && i < BUFFER_SIZE)
        {
            if (list->content[i] == '\n')
                return (true);
            i++;
        }
        list = list->next;
    }
    return (false);
}

size_t strlen_to_NL(t_list *list)
{
    size_t len;
    size_t i;
    
    if (!list)
        return (0);
    len = 0;
    while (list)
    {
        i = 0;
        while (list->content[i])
        {
            if (list->content[i] == '\n')
            {
                len++;
                return (len);
            }
            i++;
            len++;
        }
        list = list->next;
    }
    return (len);
}

void my_strcpy(char *next_str, t_list *list)
{
    size_t i;
    size_t j;

    if (!list)
        return ;
    i = 0;
    while (list)
    {
        j = 0;
        while (list->content[j])
        {
            if (list->content[j] == '\n')
            {
                next_str[i++] = '\n';
                next_str[i] = '\0';
                return ;
            }
            next_str[i++] = list->content[j++];
        }
        list = list->next;
    }
    next_str[i] = '\0';
}

void ft_free(t_list **list, t_list *clean_node, char *buf)
{
    t_list *tmp;

    if (!*list)
        return ;
    while (*list)
    {
        tmp = (*list)->next;
        free((*list)->content);
        free(*list);
        *list = tmp;
    }
    *list = NULL;
    if (clean_node->content[0])
        *list = clean_node;
    else
    {
        free(buf);
        free(clean_node);
    }
}

t_list	*my_lst_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}