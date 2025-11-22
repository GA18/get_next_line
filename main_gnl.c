/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:21:32 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/21 23:08:52 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*full_string;

	fd = open ("file.txt", O_RDONLY);
	full_string = get_next_line(fd);
	while (full_string)
	{
		write(1, full_string, ft_strlen(full_string));
		free(full_string);
		full_string = get_next_line(fd);
	}
}
