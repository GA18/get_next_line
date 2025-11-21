/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:13:48 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/20 19:20:36 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *full_string);
char	*ft_get_line(char *line);
char	*ft_new_line(char *full_string);
char	*ft_strjoin(char const *string_line, char const *buffer);
size_t	ft_strlen(const char *string);
char	*ft_strchr(const char *string, int c);

#endif