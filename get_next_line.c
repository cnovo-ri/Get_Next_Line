/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:42:39 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/19 20:54:29 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define MAX_FD 500

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
	static char		*kek[500];
	static char		*stock;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > 500)
		return (-1);
	stock = (!stock) ? ft_strnew(BUFF_SIZE) : stock;
	tmp = ft_strncpy(ft_memalloc(BUFF_SIZE), stock, BUFF_SIZE);
	while (!(ft_strchr(tmp, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
			return (real_return(ret, tmp, &line, &stock));
		buf[ret] = '\0';
		str = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = str;
	}
	*line = ft_strsub(tmp, 0, ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, '\n')));
	if ((ft_strchr(tmp, '\n')))
		stock = ft_strncpy(stock, ft_strchr(tmp, '\n') + 1, BUFF_SIZE);
	free(tmp);
	/*printf("line : %s\n\n", *line);
	printf("stock : %s\n\n", stock);
	printf(BLUE"ret : %d\n\n"NORMAL, ret);
	printf(RED"%d\n"NORMAL, 1);*/
	return (1);
}
