#include "get_next_line.h"

static void write_too_much_read (char *tmr, char **line, int i)
{
    int j;

    j = 0;
    while (tmr[j])
    {
        if (tmr[j] == '\n')
            i++;
        line[i] = line[i] + tmr[j];
        j++;
    }
}

static char *fill_too_much_read (int j, char *buff)
{
    int     i;
    char    *ret;

    i = 0;
    ret = ft_strnew(BUFF_SIZE);
    while (buff[j])
    {
        ret[i] = buff[j];
        i++;
        j++;
    }
    return (ret);
}

int get_next_line(const int fd, char **line)
{
    char                *buf;
    int                 ret;
    int                 i;
    int                 j;
    static save_buff    sb; /* la list sera en static puis recup le bon maillon (too_much_read)
                                en fonction du fd */
    i = 0;
    j = 0;
    ret = 1;
    buf = ft_strnew(BUFF_SIZE);
    buf[BUFF_SIZE - 1] = '\0';
    sb.fd = fd;
    sb.too_much_read = ft_strnew(BUFF_SIZE);
    sb.too_much_read[0] = '\0';
    while (line[i][0])
        i++;
    write_too_much_read (sb.too_much_read, line, i);
    while (ret != -1)
    {
        ret = read (fd, buf, BUFF_SIZE);
        while (buf[j] != '\n')
        {
            line[i] = line[i] + buf[j];
            j++;
        }
        sb.too_much_read = fill_too_much_read(j, buf);
        if (buf[j] == '\n')
            ret = -1;
        if (ret == 0)
            return (0);
    }
    return (1);
}