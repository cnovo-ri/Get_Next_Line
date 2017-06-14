/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:02:20 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/06/14 19:18:31 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"

# define BUFF_SIZE 4

typedef struct		s_struct
{
	char			*stock[5000];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	char			*str;
	int				ret;
}					t_struct;

int					get_next_line(const int fd, char **line);

#endif
