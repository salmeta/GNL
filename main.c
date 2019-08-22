#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int fd;
	char *line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
			printf("%s\n", line);
		close(fd);
	}

	return 0;
}