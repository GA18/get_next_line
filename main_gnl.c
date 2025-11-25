/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:21:32 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/25 18:48:43 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	size_t	i;
	char	*full_string;
	int		fd;

	i = 0;
	fd = open ("read_error.txt", O_RDONLY);
	while ((full_string = get_next_line(fd)) != NULL)
	{
		printf("Linha %zu: %s", i, full_string);
		i++;
		free(full_string);
	}
	free(full_string);
	return (0);
}
