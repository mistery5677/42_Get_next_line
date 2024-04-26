#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 7
#endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *buffer);
char	*scan_fd(char *str, int fd);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
