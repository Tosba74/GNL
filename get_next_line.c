/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:12:05 by bmangin           #+#    #+#             */
/*   Updated: 2021/01/29 13:30:36 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


int		ft_find_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_copy_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_get_after_eol(char *rest)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(rest) - i + 1))) || !(rest[i]))
	{
		free(rest);
		return (NULL);
	}
	i++;
	while (rest[i])
	{
		tmp[j++] = rest[i++];
	}
	tmp[j] = '\0';
	free(rest);
	return (tmp);
}

int		ft_create_line(char **rest, char **line, int ret)
{
	*line = ft_copy_line(*rest);
	*rest = ft_get_after_eol(*rest);
	if (ret <= 0)
	{
		free(*rest);
		return (0);
	}
	return (1);
}

#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	int					ret;
	char				buf[ARG_MAX];
	static char			*rest[OPEN_MAX];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!rest[fd])
		rest[fd] = ft_strdup("");
	while (!(ft_find_eol(rest[fd])))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free (rest);
			return (-1);
		}
		else if (ret == 0)
			break ;
		buf[ret] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buf);
	}
	return (ft_create_line(&rest[fd], line, ret));
}
