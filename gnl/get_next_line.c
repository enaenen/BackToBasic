#include "get_next_line.h"

static int read_fd(int fd, char **ret, char **buf, char **mem)
{
    char *ptr;

    while (1)
    {
        
    }
}

char    *get_next_line(int fd)
{
    char            *ret;
    char            *buf;
    int             status;
    static char     *mem[OPEN_MAX + 1];

    ret = NULL;
    if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
        return NULL;

    buf = malloc((size_t)BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    status = read_fd(fd, &ret, &buf, &mem);

}