/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:30:06 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 14:30:10 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static int	error_check(char **line)
{
	if (!line)
		return (-1);
	return (0);
}

static char	*read_file(int fd)
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		number_of_bytes_read;
	char	*freeer;

	tmp = ft_strnew(1);
	while ((number_of_bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[number_of_bytes_read] = '\0';
		freeer = tmp;
		tmp = ft_strjoin(tmp, buf);
		free(freeer);
	}
	if (number_of_bytes_read < 0)
		return (0);
	return (tmp);
}

static char	*new_line_out(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			return (ft_strsub(str, i + 1, (ft_strlen(str) - (i + 1))));
		}
		i++;
	}
	return (str);
}

static void	if_new_line(int fd, char **line, char **str)
{
	int			i;
	int			is_new_line;
	char		*save;

	i = -1;
	is_new_line = 0;
	while (str[fd][++i])
	{
		if (str[fd][i] == '\n')
		{
			*line = ft_strsub(str[fd], 0, i);
			is_new_line = 1;
			save = str[fd];
			str[fd] = new_line_out(str[fd]);
			if (save)
				free(save);
			break ;
		}
	}
	if (is_new_line == 0)
	{
		*line = ft_strsub(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = NULL;
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[5000];

	if (fd < 0 || error_check(line) == -1)
		return (-1);
	while (!str[fd])
	{
		if ((str[fd] = read_file(fd)) == 0)
			return (-1);
	}
	if (!str[fd] || str[fd][0] == '\0')
	{
		*line = NULL;
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	if_new_line(fd, line, str);
	return (1);
}
