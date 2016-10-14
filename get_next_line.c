# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdio.h>
# include "get_next_line.h"
# include "./libft/libft.h"

char	*read_tmp(const int fd, char *buf, int *bytes)
{
	char *str1;

	str1 = ft_strnew(BUFF_SIZE);
	*bytes = read(fd, str1, BUFF_SIZE);
	str1[*bytes] = '\0';
	buf = ft_strjoin(buf,(const char*)str1);
	return buf;
}

int get_next_line(const int fd, char **line)
{
	//**line is where the 
	static char *buf = "";
	char *str;
	int	bytes;
	if(fd < 0)

	bytes = 1;
	while (bytes > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != NULL)
		{
			str[0] = '\0';
			*line = ft_strdup(buf);
			buf = str + 1;
			return 1;
		}
		buf = read_tmp(fd, buf, &bytes);
	}
	return 0;
}

int		main(int argc, char **argv)
{
	if(argc > 2)
		return 0;
	int fd = open(argv[1], O_RDWR);
	char *line;
	while(get_next_line(fd, &line))
		printf("%s\n", line);

}