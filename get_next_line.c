#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	i = 1;
	str = NULL;
	while (i > 0)
	{
		if (!buffer[0])
			i = read(fd, buffer, BUFFER_SIZE);
		if (i > 0)
			str = bufferjoin(str, buffer);
		if (has_newline(buffer))
			break ;
	}
	return (str);
}
