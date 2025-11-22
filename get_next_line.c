/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:14:41 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/22 12:11:23 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
	char	*buffer_line;
	size_t	read_bytes;

	buffer_line = NULL;
	read_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(full_string, '\n')) && read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!read_bytes)
			break ;
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		buffer_line = ft_strjoin(buffer_line, buffer);
	}
	free(buffer);
	return (buffer_line);
}

char	*ft_get_line(char *line)
{
	size_t	count_bytes;
	char	*string_line;

	count_bytes = 0;
	while (line[count_bytes] != '\n' && line[count_bytes] != '\0')
		count_bytes++;
	string_line = malloc(count_bytes + 1);
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
	string_line[++count_bytes] = '\0';
	return (string_line);
}

char	*ft_new_line(char *full_string)
{
	size_t	count_bytes;
	size_t	count_remainder;
	size_t	fill_remainder;
	char	*string_line;
	char	*buffer_remainder;

	buffer_remainder = NULL;
	if (!full_string)
		return (NULL);
	count_bytes = 0;
	while (full_string[count_bytes] != '\n' && full_string[count_bytes] != '\0')
		count_bytes++;
	count_remainder = ft_strlen(full_string);
	if ((count_remainder - count_bytes) > 0)
		buffer_remainder = ft_calloc(count_remainder, sizeof(char *));
	if (!buffer_remainder)
		return (NULL);
	fill_remainder = 0;
	while (full_string[count_bytes] != '\0')
		buffer_remainder[fill_remainder++] = full_string[++count_bytes];
	buffer_remainder[count_remainder] = '\0';
	free(full_string);
	return (buffer_remainder);
}
