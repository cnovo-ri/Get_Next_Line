/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:02:20 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/20 12:49:55 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/includes/libft.h"
# include <stdio.h>

# define BUFF_SIZE 32
# define MAX_FD 500

int		get_next_line(const int fd, char **line);

#endif