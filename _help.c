#include "shell.h"
#define BUFF_SIZE 32

/**
 * read_line - print a line of fd
 * @fd: file descriptor
 * @line: line of text
 * Return: execution of read_line: 1 if success
 */
int read_line(const int fd, char **line)
{
	int			reader;
	char		*tmp;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[4864];

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	while ((reader = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (!str[fd])
			str[fd] = _strdup(buffer);
		else
		{
			tmp = f_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (_strchr(str[fd], '\n'))
			break;
	}
	if (str[fd] == NULL && reader == 0)
		return (-1);
	return (f_read_line(str, line, fd));
}

/**
 * f_read_line - read a line from fd
 * @str: grip of documment
 * @fd: file descriptor
 * @line: line of text
 * Return: 1 if success
 */
int	f_read_line(char **str, char **line, int fd)
{
	char	*tmp;
	int		count;

	count = 0;
	while (str[fd][count] != '\0' && str[fd][count] != '\n')
		count++;
	*line = f_strsub(str[fd], 0, count);
	if (str[fd][count] == '\n')
	{
		tmp = _strdup(&str[fd][count + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			f_strdel(&str[fd]);
	}
	else
		f_strdel(&str[fd]);
	return (1);
}

/**
 * _help - functions that simulate help command
 * @commands: array of strings to execute
 * Return: 0 if is positive (1 is true min.); -1 if is error
 */
int _help(char **commands)
{

	int fd, i = 1, result = -1;
	char *line = NULL;

	while (commands[i])
	{
		fd = open(commands[i], O_RDONLY);
		if (fd != -1)
		{
			result = 0;
			while (read_line(fd, &line) == 1)
			{
				puts(line);
				free(line);
			}
			close(fd);
		}
		i++;
	}

	return (result);
}
