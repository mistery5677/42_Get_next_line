#include "get_next_line.h"

size_t	ft_strlen(char *str)
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
	int j;
	int	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return 0;
		s1[0] = '\0';
	}
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if(!str)
		return NULL;
	i = -1;
	while(s1[++i])
		str[i] = s1[i];
	j = -1;
	while(s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}