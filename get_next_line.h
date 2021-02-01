/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:27:03 by bmangin           #+#    #+#             */
/*   Updated: 2021/02/01 11:17:27 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int				get_next_line(int fd, char **line);
size_t			ft_strlen(char *s);
void			ft_memdel(void *ap);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);

#endif
