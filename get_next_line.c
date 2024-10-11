#include "get_next_line.h"

#include "get_next_line.h"

char	*ft_get_buffer(int fd, char *buffer)
{
	char	*buff;
	int		readed;

	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strrchr(buff, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[readed] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*ft_get_clean(char *buffer)
{
	char	*aux;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	aux = ft_substr(buffer, i + 1, ft_strlen(buffer));
	free(buffer);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_clean(buffer);
	return (line);
}
