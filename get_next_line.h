#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ENDL '\n'
# define BUFF_SIZE 30

int get_next_line(const int fd, char **line);
int	read_tmp(const int fd, char **buf);

#endif