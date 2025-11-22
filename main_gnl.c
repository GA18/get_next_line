/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:21:32 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/22 13:46:46 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*full_string;

	fd = open ("file.txt", O_RDONLY);
	full_string = get_next_line(fd);
	printf("linha 1: %s", full_string);
	free(full_string);

	full_string = get_next_line(fd);
	printf("linha 2: %s", full_string);
	free(full_string);

	full_string = get_next_line(fd);
	printf("linha 3: %s", full_string);
	free(full_string);
	get_next_line(-1);
	return (0);
}
