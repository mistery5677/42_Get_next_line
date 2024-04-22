#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	size_t			len_s1;
	size_t			len_s2;
	char			*new_str;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[len_s1++] = s2[i];
	new_str[len_s1] = '\0';
	return (new_str);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *str;
	int 	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bytes =	read(fd, buffer, BUFFER_SIZE);
	while(bytes > 0)
	{	
		str = ft_strjoin(str, buffer);
		if(!str)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
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
}