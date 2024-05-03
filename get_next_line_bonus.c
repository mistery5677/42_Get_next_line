/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:22:06 by mistery576        #+#    #+#             */
/*   Updated: 2024/05/02 14:41:41 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_buffer(char *buffer)
{
	char	*next_line;
	size_t	end;
	size_t	i;

	end = 0;
	i = 0;
	if (buffer[end] == '\0')
		return (free(buffer), NULL);
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
	static char	*buffer[FOPEN_MAX];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) || fd > FOPEN_MAX)
		return (NULL);
	buffer[fd] = scan_fd(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	str = get_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (str);
}

/* int main()
{
	int fd[3];

	fd[0] = open("test1.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	char *test1 = get_next_line(fd[0]);
	char *test2 = get_next_line(fd[1]);
	char *test3 = get_next_line(fd[2]);
	while(test1 || test2 || test3)
	{
		printf("test1: %s\n", test1);
		printf("test2: %s\n", test2);
		printf("test3: %s\n", test3);
		test1 = get_next_line(fd[0]);
		test2 = get_next_line(fd[1]);
		test3 = get_next_line(fd[2]);
	}
	free(test1);
	free(test2);
	free(test3);

	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
} */
