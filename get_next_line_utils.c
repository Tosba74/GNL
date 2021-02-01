/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:26:38 by bmangin           #+#    #+#             */
/*   Updated: 2021/02/01 13:23:33 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		ft_memdel(void *ap)
{
	if (ap)
	{
		free(ap);
		ap = NULL;	
	}
}

char		*ft_strdup(char *src)
{
	long	i;
	char	*s;

	i = -1;
	if (!src)
		return (NULL);
	if (!(s = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i])
		s[i] = src[i];
	s[i] = '\0';
	return (s);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	if (!(s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[j])
		s[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (s);
}
