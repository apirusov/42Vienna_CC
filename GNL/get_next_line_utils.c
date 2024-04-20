
#include "get_next_line.h"

size_t strlen_to_NL(t_list *list)
{
    size_t i;
    size_t j;
    
    if (!list)
        return (0);
    i = 0;
    while (list)
    {
        j = 0;
        while (list->content[j] && list->content[j] != '\n')
            j++;
        if (list->content[j] == '\n')
            return (i + j);
        i += j;
        list = list->next;
    }
    return (i);
}

void my_strcpy(next_str, list, strlen)
{
    size_t i;
    int j;

    if (!list)
        return (NULL);
    i = 0;
    while (list && i < strlen)
    {
        j = -1;
        while (list->content[j++] && list->content[j] != '\n')
        {
            next_str[i] = list->content[j];
            i++;
        }
        if (list->content[j] == '\n')
        {
            next_str[i++] = '\n';
            next_str[i] = '\0';
            return ;
        }
        list = list->next;
    }
    next_str[i] = '\0';
}

void ft_free(t_list **list, t_list *clean_node, char *buf)
{
    t_list *tmp;

    if (!list || !clean_node || !buf)
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