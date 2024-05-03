/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:21:50 by mistery576        #+#    #+#             */
/*   Updated: 2024/05/02 14:41:50 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_buffer(char *buffer)
{
	char	*next_line;
	size_t	end;
	size_t	i;

	end = 0;
	i = 0;
	while (buffer[end] && buffer[end] != '\n')
		end++;
	if (buffer[end] == '\n')
		end++;
	next_line = malloc((ft_strlen(buffer) - end + 1) * sizeof(char));
	if (!next_line)
		return (free(next_line), NULL);
	while (buffer[end + i])
	{
		next_line[i] = buffer[end + i];
		i++;
	}
	next_line[i] = '\0';
	if (!next_line[0])
		return (free(buffer), free(next_line), NULL);
	return (free(buffer), next_line);
}

char	*get_line(char *buffer)
{
	char	*new_str;
	char	*end;
	size_t	i;

	end = ft_strchr(buffer, '\n');
	i = (ft_strlen(buffer) - ft_strlen(end)) + 1;
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = scan_fd(buffer, fd);
	if (!buffer)
		return (NULL);
	str = get_line(buffer);
	buffer = update_buffer(buffer);
	return (str);
}

/* int main()
{
	int fd = open("test1.txt", O_RDONLY);
	char *str = get_next_line(fd);
	
	printf("str: %s\n", str);
	free(str);
} */