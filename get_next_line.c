#include "get_next_line.h"
#include <stdio.h>

char *reset_buffer(char *buffer)
{
	int i;
	char *end;
	char *str;

	end = ft_strchr(buffer, '\n');
	if(!end)
	{
		free(buffer);
		return NULL;
	}
	else
		i = (end - buffer) + 1;
	if(!buffer[i])
	{
		free(buffer);
		return NULL;
	}
	str = ft_substr(buffer, i , ft_strlen(buffer) - i);
	free(buffer);
	if (!str)
		return NULL;
	return str;
}

char *get_line(char *buffer)
{
	int i;
	char *new_str;
	char *end;

	end = ft_strchr(buffer, '\n');
	i = (end - buffer) + 1;
	new_str = ft_substr(buffer, 0, i);
	if(!new_str)
		return (NULL);
	return (new_str);
}

char *scan_fd(char *str, int fd)
{
	char *buffer;
	int bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return NULL;
	buffer[0] = '\0';
	bytes = 1;
	while(bytes > 0  && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if(bytes > 0)
		{
			buffer[bytes] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free (buffer);
	if (bytes == -1)
	{
		free(str);
		return NULL;
	}
	return str;
}

char	*get_next_line(int fd)
{	
	static char *buffer;
	char 	*str;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return NULL;	
	buffer = scan_fd(buffer, fd);
	if (!buffer)
		return NULL;
	str = get_line(buffer);
	buffer = reset_buffer(buffer);
	return str;
}

/* int main()
{
	int txt = open("teste.txt", O_RDONLY);
	char *teste = get_next_line(txt);
	//char	*teste = get_next_line();
	printf("final: %s\n", teste);
	free(teste);
	close(txt);
} */