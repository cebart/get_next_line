#include "get_next_line.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char        **ft_2tabnew(int nbl, int nbc)
{
    char    **tab;
	int     i;

    i = 0;
    if (!nbl || !nbc)
        return (NULL);
    tab = (char **)malloc(sizeof(char *) * (nbl + 1));
    while(i < nbl)
    {
        tab[i] = (ft_strnew(nbc + 1));
        i++;
    }
    tab[i] = '\0';
    i++;
	return (tab);
}

int     	main(int argc, char **argv)
{
	int     fd;
	int		test;
	char	**line;
	
	line = ft_2tabnew(25, 100);
	if (argc == 1)
	{
		write(2, "fillit: missing file operand", 18);
			return (1);
	}
	else if (argc > 2)
	{
		 write(2, "Too many arguments.", 19);
			 return (1);
	}
	fd = open(argv[1], O_RDONLY);
	test = get_next_line(fd, line);
	ft_putnbr(test);
	close(fd);
	return (0);
}