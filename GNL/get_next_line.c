#include "get_next_line.h"
#include <vcruntime.h>

void clean_list(t_list **list)
{
    t_list *last;
    t_list *clean_node;
    size_t i;
    size_t j;
    char *buf;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (!clean_node || !buf)
        return (NULL);
    last = lst_last(*list);
    i = 0; 
    j = 0;
    while (last->content[i] && last->content[i] != '\n')
        i++;
    while (!last->content[i] && !last->content[++i])
        buf[j++] = last->content[i];
    buf[j] = '\0';
    clean_node->content = buf;
    clean_node->next = NULL;
    free(list);
}

char *get_line(t_list *list)
{
   int  strlen;
   char *next_str;
   if (!list)
       return (NULL);
    strlen = strlen_to_NL(list);
    next_str = malloc(sizeof(char) * strlen + 1);
    if (!next_str)
        return (NULL);
    my_strcpy(next_str, list, strlen);
    return (next_str);
}

void add_buffer(t_list **list, char *buffer)
{
    t_list *new_node;
    t_list *last;

    last = lst_last(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
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

    while (!find_newline(*list))
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        char_read = read(fd, buffer, BUFFER_SIZE);
        if (!char_read)
        {
            free(buffer);
            return (NULL);
        }
        buffer[char_read] = '\0';
        add_buffer(list, buffer);
    }
}

char *get_next_line(int fd)
{
    static t_list *list;
    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, next_line, 0) < 0)
        return (NULL);
    create_buffer(fd, &list);
    if (!list)
        return (NULL);
    next_line = get_line(list);


}