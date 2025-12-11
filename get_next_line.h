#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		has_newline(char *buffer);
char	*bufferjoin(char *str, char *buffer);

#endif