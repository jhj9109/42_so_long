/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:34:11 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 17:43:33 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*free_and_return_null(char	*p)
{
	if (p)
		free(p);
	return (NULL);
}

static char	*ft_read_and_update(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	if (save)
		if (ft_strchr((const char *)save, '\n'))
			return (save);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (1)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free_and_return_null(buff));
		buff[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		save = ft_strjoin_or_dup(save, buff);
		if (!save)
			return (free_and_return_null(buff));
		if (ft_strchr((const char *)buff, '\n'))
			break ;
	}
	free(buff);
	return (save);
}

static char	*ft_get_until_lf(char *save)
{
	int		i;
	char	*line;
	char	*p;

	i = 0;
	while (save[i])
		if (save[i++] == '\n')
			break ;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	p = line;
	while (i--)
		*p++ = *save++;
	*p = '\0';
	return (line);
}

static char	*ft_get_after_lf(char *save)
{
	int		i;
	int		c;
	char	*ret;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		return (free_and_return_null(save));
	if (save[++i] == '\0')
		return (free_and_return_null(save));
	ret = malloc(sizeof(char) * (ft_strlen((const char *)save) - i + 1));
	if (!ret)
		return (free_and_return_null(save));
	c = 0;
	while (save[i])
		ret[c++] = save[i++];
	ret[c] = '\0';
	free(save);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_update(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_until_lf(save);
	save = ft_get_after_lf(save);
	return (line);
}
