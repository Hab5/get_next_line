#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 64

int	get_next_line(const int fd, char **line);
#endif
