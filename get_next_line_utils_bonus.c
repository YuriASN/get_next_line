#include "get_next_line_bonus.h"

/** @brief
 * Returns TRUE or FALSE if the string
 * passed as a parameter has a new line.
 * Already clear buffer data moving the data
 * from after \\n to beggining of it (buffer[0]). */
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

/** @brief
 * Returns length of string, up to end of it or first 
 * new line found. */
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

/** @brief
 * Returns an allocated string from the concatenation of str
 * and buffer, up to \\n of \0.
 * @param str
 * String that will be add to.
 * @param buffer
 * String that will be added from.
 * @return
 * Concatenation of both strings, up to first \\n is found or \0.
 */
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
