#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main (void)
{
    int fd;
    char *line;

    fd = open ("./tests/test", O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("line = %s \n", line);
        free(line);
    }
}