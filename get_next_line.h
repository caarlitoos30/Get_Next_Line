#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, size_t i);
void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *str);

#endif
