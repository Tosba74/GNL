/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:39:30 by bmangin           #+#    #+#             */
/*   Updated: 2021/01/29 13:21:53 by bmangin          ###   ########lyon.fr   */
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

	fd = open("../test1", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("LINE => |%s|\n", line);
		free(line);
	}
	printf("LINE => |%s|\n", line);
	free(line);
	close(fd);
	getchar();
	return (0);
}

// int main()
// {
// 	while (1)
// 		ft_main();
// 	return(0);
// }