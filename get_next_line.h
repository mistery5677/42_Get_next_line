#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2);
char *get_line(char *buffer);
int find_newline(char *str);
char *scan_fd(char *str, int fd);
int find_newline(char *buffer);
void	ft_strcpy(char *str, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t  len);

char *get_next_line(int fd);
