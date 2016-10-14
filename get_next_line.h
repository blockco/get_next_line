#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ENDL '\n'
# define BUFF_SIZE 999999

int get_next_line(const int fd, char **line);
char *read_tmp(const int fd, char *buf, int *bytes);

#endif