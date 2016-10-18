# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdio.h>
# include "get_next_line.h"
# include "./libft/libft.h"

// read_buffer
// buffer

int read_tmp(const int fd, char **buf)
{
	char	str1[BUFF_SIZE + 1];
	//char    *temp;
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
	//**line is where the
	static char *buf;
	char 		*str;
	int			bytes_read;

	if(fd < 0)
		return (-1);
	if (line == NULL || *line == NULL)
		return (-1);
	if (!buf)
		buf = ft_strnew(BUFF_SIZE);
	bytes_read = read_tmp(fd, &buf);
	if((str = ft_strchr(buf, '\n')))
	{
		str[0] = '\0';
		*line = ft_strdup(buf);
		buf = str + 1;
	}
	else
	{
		*line = ft_strdup(buf);
	}
	if (bytes_read == 0)
		return (0);
	else
		return (1);
}

// int		main(int argc, char **argv)
// {
// 	if(argc > 2)
// 		return 0;
// 	int fd = open(argv[1], O_RDWR);
// 	char *line = ft_strnew(0);
// 	while(get_next_line(fd, &line))
// 		printf("%s\n", line);
// }
