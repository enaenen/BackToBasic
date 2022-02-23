#include "get_next_line.h"

static int get_one_line(char *ptr, char **ret,char **mem)
{
    char *tmp;

    if (ptr)
    {
        *ret = gnl_strndup(*mem, ptr - *mem + 1);
        *tmp = gnl_strndup(ptr + 1, gnl_strlen(ptr + 1));
        if (!ret || !tmp)
            return (ERROR);
        free (*mem);
        *mem = tmp;
        return (SUCCESS);        
    }
    else
    {
        if (!*mem || !**mem)
        {
            *ret = NULL;
            free(*mem);
        }
        else
            *ret = *mem;
        *mem = NULL;
        return (END_OF_FILE);
    }
}

static int read_fd(int fd, char **ret, char **buf, char **mem)
{
    char *ptr;
    char *tmp;
    ssize_t read_len;
    while(1)
    {
        ptr = gnl_strchr(*mem, '\n');
        if(ptr)
            break;
        read_len = read(fd, *buf, BUFFER_SIZE);
        if (read_len == -1)
            return (ERROR);
        if (read_len == 0)
            break;
        (*buf)[read_len] = '\0';
        tmp = gnl_strjoin(*mem, *buf);
        if (!tmp)
            return (ERROR);
        free(*mem);
        *mem = tmp;
    }
    return get_one_line(&ptr, &ret, &mem);
}

char    *get_next_line(int fd)
{
    char *ret;
    char *buf;
    static char *mem[OPEN_MAX + 1];
    int status;

    ret = NULL;
    if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
        return (NULL);
    if (!mem[fd])
         mem[fd] = gnl_strndup("", 0);
    buf = malloc((size_t)BUFFER_SIZE + 1);
    if (!mem[fd] || !buf)
        return (NULL);
    status = read_fd(fd, &ret, &buf, &mem[fd]);
    return (ret);
}