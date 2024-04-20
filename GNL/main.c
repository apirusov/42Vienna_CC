#include "get_next_line.h"

int main ()
{
    int fd;
    char *line;
    int lines = 1;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("fd-> %s\n", lines++, line);
    close(fd);
    return (0);
}