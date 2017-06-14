/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:42:39 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/06/14 19:27:12 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		real_return(int fd, t_struct *s, char ***line)
{
	if (s->ret < 0)
		return (-1);
	if (ft_strlen(s->tmp) > 0)
	{
		**line = s->tmp;
		s->stock[fd] = NULL;
		return (1);
	}
	**line = NULL;
	s->stock[fd] = NULL;
	free(s->tmp);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_struct		s;

	if (fd < 0 || fd > 5000 || !line)
		return (-1);
	s.stock[fd] = (!s.stock[fd]) ? ft_strnew(BUFF_SIZE) : s.stock[fd];
	s.tmp = ft_strcpy(ft_strnew(BUFF_SIZE), s.stock[fd]);
	while (!(ft_strchr(s.tmp, '\n')))
	{
		if ((s.ret = read(fd, s.buf, BUFF_SIZE)) < 1)
			return (real_return(fd, &s, &line));
		s.buf[s.ret] = '\0';
		s.str = ft_strjoin(s.tmp, s.buf);
		free(s.tmp);
		s.tmp = s.str;
	}
	*line = ft_strsub(s.tmp, 0, ft_strlen(s.tmp) -
			ft_strlen(ft_strchr(s.tmp, '\n')));
	if (ft_strchr(s.tmp, '\n'))
		s.stock[fd] = ft_strncpy(s.stock[fd], ft_strchr(s.tmp, '\n') +
				1, BUFF_SIZE);
	return (1);
}
