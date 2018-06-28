#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include "get_next_line.h"
# define BUFF_SIZE 10

typedef struct save_buff
{
    int     fd;
    char    *too_much_read;
} save_buff;


int get_next_line(const int fd, char **line);
#endif
