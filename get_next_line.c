#include "get_next_line.h"

char *get_line(char *buffer)
{
	int str_len;
	char *new_str;

	str_len = find_newline(buffer);
	new_str = malloc((str_len + 1) * sizeof(char));
	if (!new_str)
		return NULL;
	ft_strcpy(new_str, buffer);
	new_str[str_len] = '\0';
	free(buffer);
	return new_str;
}

char *scan_fd(char *str, int fd)
{
	char *buffer;
	int bytes;

	buffer = NULL;
	bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return NULL;
	while(bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return NULL;
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if(!str)
		{
			free (buffer);
			return NULL;
		}
	}
	free (buffer);
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
	return str;
}

int main()
{
	int txt = open("teste.txt", O_RDONLY);
	char *teste = get_next_line(txt);
	//char	*teste = get_next_line();
	printf("final: %s\n", teste);
	free(teste);
	close(txt);
}