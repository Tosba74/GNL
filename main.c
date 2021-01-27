/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:39:30 by bmangin           #+#    #+#             */
/*   Updated: 2021/01/21 16:22:58 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>

#include <stdio.h>

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("../../test2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("LINE => |%s|\n", line);
		free(line);
	}
	printf("LINE => |%s|\n", line);
	free(line);
	close(fd);
	return (0);
}
