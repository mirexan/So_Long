#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char	*argv[])
{
	int		fd;
	int		i;
	char	*line;

	i = 1;
	if (argc < 2)
	{
		printf("Please insert an argument\n");
		return (1);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)	
		{
			printf("There's no file,insert text until ctrl+d\n");
			fd = 0;
		}
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free (line);
		}
		if (fd != 0)
			close(fd);
		i++;
	}
	return (0);
}
