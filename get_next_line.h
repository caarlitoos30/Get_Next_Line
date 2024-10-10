#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//INCLUDES
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//GET_NEXT_LINE
char	*get_next_line(int fd);

//GET_NEXT_LINE_UTILS
int		ft_strlen(char *str);
char	*ft_strrchr(char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *stash, char *buff);
char	*ft_substr(char *s, int start, int len);

#endif
