#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int 	result;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	do
	{
		result = get_next_line(fd, &line);
		printf("\t\t\t ********** %i : [%s]\n",result,line);
		//printf("[%s]\n",line);
	} while(result>0) ;
/*
	while(get_next_line(fd, &line))
		printf("%s\n",line);
	printf("%s\n", line);
*/	
	close(fd);
  	return (0);
}
