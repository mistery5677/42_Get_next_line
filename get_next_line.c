#include "get_next_line.h"

int found_newline(char *buffer)
{
	int i;

	i = 0;
	while(buffer[i])
	{
		if(buffer[i] == '\n')
		{
			printf("cbum\n");
			return (1);
		}
		i++;
	}
	return 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/* char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	int len_s1;
	int len_s2;
	int i;

	i = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	while(s1[++i])
		str[i] = s1[i];
	i = -1;
	while(s2[++i] && s2[i] != '\n')
	{
		str[len_s1] = s2[i];
		len_s1++;
	}
	str[len_s1] = '\0';
	free(s1);	
	return str;
} */

char	*ft_strjoin(char *s1, char *s2, int bytes) //How many bytes im gonna pass
{
	char *str;
	int len_s1;
	int len_s2;
	int i;

	i = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if(!str)
		return NULL;
	while(s1[++i])
		str[i] = s1[i];
	i = -1;
	while(s2[++i] && i < bytes)
	{
		if (s2[i] == '\n')
			str[len_s1] = '\n';
		str[len_s1] = s2[i];
		len_s1++;
	}
	str[len_s1] = '\0';
	free(s1);	
	return str;
}

char	*get_next_line(int fd)
{	
	static char buffer[BUFFER_SIZE + 1];
	char 	*str;
	int 	bytes;

	if(fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX) //protection
		return NULL;
	str = NULL;
	bytes = read(fd, buffer, BUFFER_SIZE);
		
	if(!str)
		return NULL;
	while(bytes  > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer, bytes);
	}
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