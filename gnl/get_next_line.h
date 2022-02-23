#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 48
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# define ERROR -1
# define END_OF_FILE 0
# define SUCCESS 1

size_t  gnl_strlen(const char *);
char    *gnl_strndup(const char *, size_t);
char    *gnl_strchr(const char *, int);
char    *gnl_strjoin(char const *, char const *);

#endif