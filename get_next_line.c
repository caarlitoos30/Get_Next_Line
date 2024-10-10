#include "get_next_line.h"

char	*ft_get_stash(int fd, char *stash)
{
	char	*buff;
	int		readed;

	if (!stash)
		stash = ft_calloc(sizeof(char), 1);
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
			free(stash);
			return (NULL);
		}
		buff[readed] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (stash[i] == '\n')
		line[i] = stash[i];
	return (line);
}

char	*ft_get_clean(char *stash)
{
	char	*aux;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	aux = ft_substr(stash, i + 1, ft_strlen(stash));
	free(stash);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = ft_get_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_get_clean(stash);
	return (line);
}
