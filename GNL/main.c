#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);

    char *line;
    line = get_next_line(fd);
    printf("line: %s\n", line);
    free(line);
    line = get_next_line(fd);
}