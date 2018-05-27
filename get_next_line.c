#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
    char        *buf;
    int         ret;
    int         i;

    i = 0;
    ret = 1;
    buf = ft_strnew(BUFF_SIZE);
    buf[0] = '\0';
    while (line[i][0])
        i++;
    while (ret != -1)
    {
        ret = read (fd, buf, 1);
        if (buf[0] == '\n')
            ret = -1;
        else
            line[i] = ft_strcat(line[i], buf);
        if (ret == 0)
            return (0);
    }
    return (1);
}