#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int 	len_s1;
	int 	len_s2;
	int	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = -1;
	printf("%d %d\n", len_s1, len_s2);
	str = malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	
	if(!str)
		return NULL;
	while(s1[++i])
		str[i] = s1[i];
	i = -1;
	while(s2[++i])
	{
		str[len_s1] = s2[i];
		len_s1++;
	}
	str[len_s1] = '\0';
	free(s1);
	return str;
}

char *get_line(char *buffer)
{
	int str_len;
	char *new_str;

	str_len = ft_strlen(buffer);
	new_str = malloc((str_len + 1) * sizeof(char));
	if (!new_str)
		return NULL;
	new_str = ft_strjoin(new_str, buffer);
	if (new_str)
		return NULL;
	return new_str;
}

int find_newline(char *str)
{
	int i;

	i = -1;
	while(str[++i])
	{
		if(str[i] == '\n')
			return 1;
	}
	return 0;
}

char *scan_fd(char *str, int fd)
{
	char *buffer;
	int bytes;

 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return NULL;
	bytes = 1;
	printf("teste1\n");
	while(bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		printf("%s", buffer);
		if (bytes == -1)
		{
			free(buffer);
			return NULL;
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer); //Creates my string
		if (find_newline(str) == 1)
			break ;
	}
	free (buffer);
	return str;
}

char	*get_next_line(int fd)
{	
	static char *buffer;
	char 	*str;

	printf("teste\n");
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
	printf("teste: %s\n", teste);
	//char	*teste = get_next_line();
	free(teste);
	close(txt);
}