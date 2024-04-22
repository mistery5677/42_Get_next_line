#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char 	*str;
	int 	bytes;

	bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes + 1] = '\0';
		str = ft_strjoin(str, buffer);
		if(!str)
		{
			free(str);
			return (NULL);
		}
		str[bytes] = '\0';
	}
	return (str);
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