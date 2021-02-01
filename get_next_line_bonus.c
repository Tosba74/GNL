/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:26:54 by bmangin           #+#    #+#             */
/*   Updated: 2021/02/01 13:13:59 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		ft_find_eol(char *s)
{
	int			i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (1);
	return (0);
}

static char		*ft_copy_line(char *s, char *line)
{
	int			i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		line[i] = s[i];
	line[i] = '\0';
	return (line);
}

static char		*ft_after_eol(char *rest)
{
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!(rest[i]))
	{
		ft_memdel(rest);
		return (NULL);
	}
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(rest) - i + 1))))
	{
		ft_memdel(rest);
		return (NULL);
	}
	i++;
	while (rest[i])
		tmp[j++] = rest[i++];
	tmp[j] = '\0';
	ft_memdel(rest);
	return (tmp);
}

static int		ft_create_line(char **rest, char **line, int ret)
{
	*line = ft_copy_line(*rest, *line);
	*rest = ft_after_eol(*rest);
	if (ret == 0)
	{
		ft_memdel(*rest);
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[ARG_MAX];
	static char	*rest[OPEN_MAX];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	if (!rest[fd])
		rest[fd] = ft_strdup("");
	while (ft_find_eol(rest[fd]) != 1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			ft_memdel(rest[fd]);
			return (-1);
		}
		else if (ret == 0)
			break ;
		buf[ret] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buf);
	}
	return (ft_create_line(&rest[fd], line, ret));
}
