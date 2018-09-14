/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:16:55 by omeyer            #+#    #+#             */
/*   Updated: 2017/09/28 20:25:57 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_var
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*temp;
	char		*save;
}				t_var;

int				get_next_line(const int fd, char **line);
int				finish_line(t_var *var, int fd, char **line);
#endif
