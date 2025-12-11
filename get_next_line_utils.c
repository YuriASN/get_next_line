#include "get_next_line.h"

/* Check if buffer has newline. If it has it moves
the byte after newline to buffer[0] and returns TRUE.
if not it erases all bytes of buffer and return FALSE*/
int	has_newline(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buffer[i])
	{
		if (j >= 0)
			buffer[j++] = buffer[i];
		if (j == -1 && buffer[i] == '\n')
			j = 0;
		buffer[i++] = 0;
	}
	return (j >= 0);
}

//Count the size of string until \n or the end.
static int	part_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

//Returns a pointer to the result of concatenation of string and buffer.
char	*bufferjoin(char *str, char *buffer)
{
	int		j;
	char	*temp;

	j = 0;
	temp = malloc(part_str(buffer) + part_str(str) + 1);
	if (!temp)
		return (NULL);
	while (str && str[j])
	{
		temp[j] = str[j];
		j++;
	}
	while (*buffer)
	{
		temp[j++] = *buffer;
		if (*buffer++ == '\n')
			break ;
	}
	temp[j] = 0;
	if (str)
		free(str);
	return (temp);
}
