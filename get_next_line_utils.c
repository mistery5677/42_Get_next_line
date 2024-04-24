#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return 0;
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

int find_newline(char *buffer)
{
	int i;
	int len;

	len = 0;
	i = -1;
	while(buffer[++i])
	{
		if (buffer[i] == '\n')
		{
			len++;
			return len;
		}
		else
			len++;
	}
	return len;
}

void	ft_strcpy(char *str, char *buffer)
{
	size_t	i;

	i = -1;
	while (buffer[++i])
	{
		if(buffer[i] == '\n')
		{
			str[i++] = '\n';
			str[i] = '\0'; 
			return ;
		}
		str[i] = buffer[i];
	}
	str[i] = '\0';
}

