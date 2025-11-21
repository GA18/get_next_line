/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:14:41 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/20 22:24:33 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char	*full_string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_string = ft_read_line(fd, full_string);
	if (!full_string)
		return (NULL);
	line = ft_get_line(full_string);
	full_string = ft_new_line(full_string);
	return (line);
}

char	*ft_read_line(int fd, char *full_string)
{
	char	*buffer;
	size_t	read_bytes;

	read_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(full_string, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		full_string = ft_strjoin(full_string, buffer);
	}
	free(buffer);
	return (full_string);
}

char	*ft_get_line(char *line)
{
	size_t	count_bytes;
	char	*string_line;

	count_bytes = 0;
	while (line[count_bytes] != '\n' && line[count_bytes] != '\0')
		count_bytes++;
	string_line = malloc(count_bytes + 2);
	if (!string_line)
		return (NULL);
	count_bytes = 0;
	while (line[count_bytes] != '\n' && line[count_bytes] != '\0')
	{
		string_line[count_bytes] = line[count_bytes];
		count_bytes++;
	}
	if (line[count_bytes] == '\n')
		string_line[count_bytes] = line[count_bytes];
		string_line[count_bytes] = '\0';
	return (string_line);
}

char	*ft_new_line(char *full_string)
{
	size_t	count_newline;
	size_t	count_remainder;
	char	*string_remainder;

	count_newline = 0;
	if (!full_string)
		return (NULL);
	while (full_string && full_string[count_newline] != '\n')
		count_newline++;
	count_remainder = (ft_strlen(full_string)) - count_newline;
	string_remainder = malloc(sizeof(char) * count_remainder);
	if (!string_remainder)
		return (NULL);
	while ((count_remainder + count_newline) != 0)
	{
		string_remainder = full_string[++count_newline];
		string_remainder++;
		count_remainder--;
	}
	free(full_string);
	return (string_remainder);
}
