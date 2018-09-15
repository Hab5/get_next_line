#include "../get_next_line.h"

int		reset_stock(char **line, char **stock)
{
	*line = *stock;
	*stock = NULL;
	return (1);
}

int		check_n(char *stock)
{
	int		i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		clean_stock(char **line, char **stock)
{
	char	*temp;
	int		len;

	len = ft_strlen(*stock);
  *line = ft_strsub(*stock, 0, check_n(*stock)); // line = *\n[stock]
	temp = *stock;
  printf("\n--STOCK\n%s--STOCK\n", temp); /*DEBUGGING*/
	*stock = ft_strsub(*stock, check_n(*stock) + 1, len - check_n(*stock));
	//delete the first line from stock.
	free(temp);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*stock;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!stock)
  		stock = ft_strdup("");

	ret = 0;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
    printf("\n--BUFFER\n%s--BUFFER\n", buf); /*DEBUGGING*/
		stock = ft_strjoinfree(stock, buf); // stock = buffer + stock
		if (check_n(stock) != -1)
			return (clean_stock(line, &stock));
	}
	if (ret == -1) // if read() error.
		return (-1);
	if (check_n(stock) != -1) // if (!stock(i)), clean and return.
		return (clean_stock(line, &stock));
	if (ft_strlen(stock) != 0) // if there is something in stock, reset.
		return (reset_stock(line, &stock));
	return (0);
}
