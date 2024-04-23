#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_strlen(char *str);
int found_newline(char *buffer);
char	*ft_strjoin(char *s1, char *s2, int bytes);

char *get_next_line(int fd);
