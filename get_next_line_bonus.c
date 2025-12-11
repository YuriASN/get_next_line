#include "get_next_line_bonus.h"

/** @brief
 * Function reads from FD and returns a single line from it
 * on each call.
 * @param fd
 * File descriptor that will be read from.
 * @return
 * Allocated string that was read from FD.
 * Or NULL in case of error or file ended. */
char	*get_next_line(int fd)
{
	static char		buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*str;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (0);
	i = 1;
	str = NULL;
	while (i > 0)
	{
		if (!buffer[fd][0])
			i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > 0)
			str = bufferjoin(str, buffer[fd]);
		if (has_newline(buffer[fd]))
			break ;
	}
	return (str);
}
