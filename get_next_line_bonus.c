/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:26:22 by bmangin           #+#    #+#             */
/*   Updated: 2021/01/27 11:33:19 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * i + 1)))
	{
		if (rest)
			free(rest);
		return (NULL);
	}
	while (rest[++i] != '\n' && rest[i])
		line[i] = rest[i];
	line[i] = '\0';
	return (line);
}

char	*ft_after_oel(char *rest)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!(s = malloc(sizeof(char) * (ft_strlen(rest) - i))) || !rest[i])
	{
		if (rest)
			free(rest);
		return (NULL);
	}
	while (rest[++i])
		s[j++] = rest[i];
	s[j] = '\0';
	return (s);
}

int		ft_create_line(char *rest, char **line, int ret)
{
	*line = ft_copy_line(rest, *line);
	if (ret == 0)
	{
		if (rest)
			free(rest);
		return (0);
	}
	else
		rest = ft_after_oel(rest);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[ARG_MAX];
	static char		*rest[OPEN_MAX];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (rest[fd] == NULL)
		rest[fd] = ft_strdup("");
	while (ft_find_eol(rest[fd]) == -1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			if (rest[fd])
				free(rest[fd]);
			return (-1);
		}
		buf[ret] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buf);
		if (ret == 0)
			break ;
	}
	return (ft_create_line(rest[fd], line, ret));
}
