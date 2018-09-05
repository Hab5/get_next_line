#include "../get_next_line.h"

int main(int argc, char **argv)
{
	char *str;
	int fd;

	if (argc < 0)
		return (-1);

	str = NULL;

  	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str) != 0)
	{
		printf("[%s]\n", str);
		free(str);
	}

  ft_putstr("\nEND OF FILE\n");
  close(fd);
	return (0);
}
