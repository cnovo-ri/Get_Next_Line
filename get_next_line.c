/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:42:39 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/20 14:55:49 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		real_return(int ret, char *tmp, char ***line, char **stock)
{
	if (ret < 0)
		return (-1);
	if (ft_strlen(tmp) > 0)
	{
		**line = tmp;
		*stock = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stock[MAX_FD];
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > MAX_FD)
		return (-1);
	stock[fd] = (!stock[fd]) ? ft_strnew(BUFF_SIZE) : stock[fd];
	tmp = ft_strncpy(ft_memalloc(BUFF_SIZE), stock[fd], BUFF_SIZE);
	while (!(ft_strchr(tmp, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
			return (real_return(ret, tmp, &line, &stock[fd]));
		buf[ret] = '\0';
		str = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = str;
	}
	*line = ft_strsub(tmp, 0, ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, '\n')));
	if ((ft_strchr(tmp, '\n')))
		stock[fd] = ft_strncpy(stock[fd], ft_strchr(tmp, '\n') + 1, BUFF_SIZE);
	free(tmp);
	return (1);
}
