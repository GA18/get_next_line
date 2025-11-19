/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:40:26 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/18 21:45:04 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *string_line, char const *buffer)
{
	char	*full_string;
	size_t	index_str;

	if (!string_line || !buffer)
		return (NULL);
	full_string = malloc((ft_strlen(string_line) + ft_strlen(buffer) + 1)
			* (sizeof(char)));
	if (!full_string)
		return (NULL);
	index_str = 0;
	while (*string_line)
	{
		full_string[index_str] = *string_line;
		index_str++;
		string_line++;
	}
	while (*buffer)
	{
		full_string[index_str] = *buffer;
		index_str++;
		buffer++;
	}
	full_string[index_str] = '\0';
	free(string_line);
	return (full_string);
}

char	*ft_strchr(const char *string, int c)
{
	int	index;

	index = 0;
	while ((unsigned char)string[index])
	{
		if ((unsigned char)string[index] == (unsigned char)c)
			return ((char *)&string[index]);
		index++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&string[index]);
	return (NULL);
}

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (*string++)
		length++;
	return (length);
}
