#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd);
