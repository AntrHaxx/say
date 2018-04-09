#include "say.h"

bool	ft_read_fd(int fd, char **str)
{
	int		i;
	int		bytes;
	int		size;
	char	buff[16384];

	i = 0;
	bytes = 0;
	size = 1;
	*str = NULL;
	while ((bytes = read(fd, buff, 16383)))
	{
		size += bytes;
		*str = realloc(*str, size);
		while (i < size)
		{
			(*str)[i] = buff[size - bytes + i];
			i++;
		}
	}
	if (bytes == -1 && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (bytes == -1 ? false : true);
}

bool	ft_read_file(char *file, char **str)
{
	int	fd;

	*str = NULL;
	if ((fd = open(file, O_RDWR)) == -1)
		return (false);
	if (! ft_read_fd(fd, str))
		return (false);
	if (close(fd) == -1)
		return (false);
	return (true);
}

bool	ft_read_stdin(char **str)
{
	*str = NULL;
	return (ft_read_fd(0, str));
}
