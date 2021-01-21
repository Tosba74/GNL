/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:26:22 by bmangin           #+#    #+#             */
/*   Updated: 2021/01/21 12:31:30 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_find_eol(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_copy_line(char *rest, char *line)
{
	int		i;
	int		len;

	i = -1;
	len = ft_find_eol(rest);
	if (len == -1)
		len = ft_strlen(rest);
	if (!(line = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (rest[++i] != '\n' && rest[i])
	{
		line[i] = rest[i];
	}
	line[i] = '\0';
	return (line);
}

char	*ft_after_oel(char *rest)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rest[i] != '\n')
		i++;
	while (rest[++i])
		rest[j++] = rest[i];
	rest[j] = '\0';
	return (rest);
}

int		ft_create_line(char *rest, char **line, int ret)
{
	if (ret < BUFFER_SIZE)
	{
		*line = ft_strdup(rest);
		free(rest);
		return (0);
	}
	else
	{
		*line = ft_copy_line(rest, *line);
		rest = ft_after_oel(rest);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	static char		*rest;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (rest == NULL)
		rest = ft_strdup("");
	while (ft_find_eol(rest) == -1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
		rest = ft_strjoin(rest, buf);
		if (ret < BUFFER_SIZE)
			break ;
	}
	return (ft_create_line(rest, line, ret));
}
