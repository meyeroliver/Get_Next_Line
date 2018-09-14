/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:16:27 by omeyer            #+#    #+#             */
/*   Updated: 2017/09/28 20:25:59 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_var	var;

	if (line == NULL)
		return (-1);
	*line = ft_strnew(0);
	if (var.save)
	{
		var.temp = *line;
		*line = ft_strjoin(var.temp, var.save);
		free(var.temp);
		if (ft_strchr(*line, '\n'))
		{
			var.save = ft_strdup(ft_strchr(*line, '\n'));
			var.temp = *line;
			*line = ft_strsub(var.temp, 0, ft_strlen(var.temp)
						- ft_strlen(var.save));
			free(var.temp);
			var.save++;
			return (1);
		}
		var.save = NULL;
	}
	return (finish_line(&var, fd, line));
}

int		finish_line(t_var *var, int fd, char **line)
{
	while (((var->ret = read(fd, var->buf, BUFF_SIZE)) > 0))
	{
		var->buf[var->ret] = '\0';
		if (ft_strchr(var->buf, '\n'))
		{
			var->save = ft_strdup(ft_strchr(var->buf, '\n'));
			var->temp = *line;
			*line = ft_strjoin(var->temp, ft_strsub(var->buf, 0,
						ft_strlen(var->buf) - ft_strlen(var->save)));
			free(var->temp);
			var->save++;
			return (1);
		}
		var->temp = *line;
		*line = ft_strjoin(var->temp, var->buf);
		free(var->temp);
	}
	if (var->ret < 0)
		return (var->ret);
	if (**line)
		return (1);
	return (0);
}
