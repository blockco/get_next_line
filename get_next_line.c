
# include "get_next_line.h"
# include "./libft/libft.h"

int read_tmp(const int fd, char **buf)
{
	char	str1[BUFF_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(*buf, '\n') == NULL)
	{
		bytes_read = read(fd, &str1, BUFF_SIZE);
		if (bytes_read < 0)
			return (-1);
		str1[bytes_read] = '\0';
		*buf = ft_strjoin(*buf,(const char*)str1);
		ft_bzero(str1, BUFF_SIZE);
	}
	return (bytes_read);
}

int get_next_line(const int fd, char **line)
{
	static char *buf;
	char 		*str;
	int			bytes_read;

	if (fd < 0 || line == NULL || (-1 == read(fd, buf, 0)))
		return (-1);
	if (!buf)
		buf = ft_strnew(BUFF_SIZE);
	bytes_read = read_tmp(fd, &buf);
	if (bytes_read == -1)
		return (-1);
	if ((str = ft_strchr(buf, '\n')))
	{
		str[0] = '\0';
		*line = ft_strdup(buf);
		buf = str + 1;
		return 1;
	}
	*line = ft_strdup(buf);
	buf = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
