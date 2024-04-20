#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# idndef BUFFER_SIZE
#   define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_list
{
    char			*content;
    struct s_list	*next;
}	t_list;

/**********************************GET NEXT LINE***********************************/
char *get_next_line(int fd);