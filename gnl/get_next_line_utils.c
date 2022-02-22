#include "get_next_line.h"

size_t  gnl_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *gnl_strchr(const char *s, int c)
{
    char    *ptr;

    ptr = (char *)s;
    while (*ptr && *ptr != (char) c)
        ptr++;
    if (*ptr == (char)c)
        return (ptr);
    return (NULL);
}

char    *gnl_strndup(const char *s, size_t n)
{
    char *ret;
    char *tmp;

    ret = malloc(n + 1);
    if (!ret)
        return (NULL);
    tmp = ret;
    while (n--)
        *tmp++ = *s++;
    tmp = '\0';
    return (ret);
}

char    *gnl_strjoin(char const *s1, char const *s2)
{
    char *ret;
    int i;
    int j;
    
    i = 0;
    j = 0;
    ret = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
    if (!ret)
        return (NULL);
    while (s1[i])
    {
        ret[i] = s1[i];
        i++;
    }
    while (s2[j])
        ret[i++] = s2[j++];
    ret[i] = '\0';
    return (ret);
}