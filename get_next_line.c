#include "get_next_line.h"

static int count_char_line(const int fd, char *buf)
{
    int ret;
    int len_line;

    len_line = -2;
    ret = 1;
    while (ret != 0 && buf[0] != '\n')
    {
        ret = read (fd, buf, 1);
        len_line++;
    }
    return (len_line);
}

int get_next_line(const int fd, char **line)
{
    char    *buf;
    int     nb_char;
    char    *line_temp;

    line[0][0] = '\0'; /* a suppr */
    buf = ft_strnew(BUFF_SIZE);
    nb_char = count_char_line(fd, buf);
    line_temp = ft_strnew(nb_char);
    while 
    return (nb_char);
}