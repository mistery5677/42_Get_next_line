#include "get_next_line.h"
#include <stdio.h>

/* char	*update_buffer(char *buffer)
{
	char	*end;
	char	*str;
	int		i;

	end = ft_strchr(buffer, '\n');
	if (!end)
	{
		free(buffer);
		return (NULL);
	}
	else
		i = (end - buffer) + 1;
	// printf("end_str = %s\n end_char = %c\n", end, end[i]);
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	if (!str)
		return (NULL);
	// printf("str_len: %zu\n str: %s\n", ft_strlen(str), str);
	return (str);
} */

size_t	find_line_ending(char *str, size_t i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*get_string(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (free(str), NULL);
	i = find_line_ending(str, i);
	new_str = (char *)malloc((ft_strlen(str) - i + 1));
	if (!new_str)
		return (free(new_str), NULL);
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	if (!new_str[0])
		return (free(str), free(new_str), NULL);
	free(str);
	return (new_str);
}

char *update_buffer(char *buffer)
{
	char *next_line;
	int end;
	int i;

	end = 0;
	i = 0;
	if (buffer[end] == '\0')
	{
		free(buffer);
		return NULL;
	}
	while(buffer[end] && buffer[end] != '\n')
		end++;
	if (buffer[end] == '\n')
		end++;
	next_line = malloc((ft_strlen(buffer) - end + 1) * sizeof(char*));
	if(!next_line)
	{
		free(buffer);
		return NULL;
	}
	while(buffer[end])
	{
		next_line[i] = buffer[i + end];
		i++;
	}
	next_line[i] = '\0';
	if (!next_line[0])
		return (free(buffer), free(next_line), NULL);
	free (buffer);
	return next_line;
}

char	*get_line(char *buffer)
{
	char	*new_str;
	char	*end;
	int		i;

	end = ft_strchr(buffer, '\n');
	i = (end - buffer) + 1;
	new_str = ft_substr(buffer, 0, i);
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	*scan_fd(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free(buffer);
	if (bytes == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buffer = scan_fd(buffer, fd);
	if (!buffer)
		return (NULL);
	// printf("buffer no get next line: %zu\n buffer: %s\n", ft_strlen(buffer), buffer);
	str = get_line(buffer);
	buffer = update_buffer(buffer);
	return (str);	
}

/* int main()
{
	int txt = open("teste.txt", O_RDONLY);
	char *teste ;
	teste = get_next_line(txt);
	int count = 1;
	while(teste && count < 6)
	{
		printf("final: [%d]	%s\n", count, teste)	;
		free(teste);
		teste = get_next_line(txt);
		count++;
	}
	close(txt);
} */