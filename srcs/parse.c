/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:32:06 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 19:32:07 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	parse_init(t_args *x, char **lines, int fd, bool *failed)
{
	char	*ret;

	ret = get_next_line(fd);
	if (ret == NULL)
		return (false);
	if (ret[ft_strlen(ret) - 1] == '\n')
		ret[ft_strlen(ret) - 1] = '\0';
	x->w = ft_strlen(ret);
	x->h = 1;
	*failed = false;
	*lines = ret;
	return (true);
}

static bool	read_line(t_args *x, char **lines, int fd, bool *failed)
{
	char	*ret;

	ret = get_next_line(fd);
	if (ret == NULL)
		return (false);
	if (ret[ft_strlen(ret) - 1] == '\n')
		ret[ft_strlen(ret) - 1] = '\0';
	if (*failed)
		free(ret);
	else if (x->w != ft_strlen(ret))
	{
		*failed = true;
		free(ret);
	}
	else
	{
		*lines = ft_strjoin(*lines, ret);
		if (*lines == NULL)
			exit_error(x, "malloc fail");
		free(ret);
		x->h = x->h + 1;
	}
	return (true);
}

static void	create_map(t_args *x, int w, int h)
{
	int	i;
	int	**m;

	m = ft_calloc(h, sizeof(int **));
	if (m == NULL)
		exit_error(x, "malloc fail");
	i = -1;
	while (++i < h)
	{
		m[i] = ft_calloc(w, sizeof(int *));
		if (m[i] == NULL)
		{
			while (--i >= 0)
				free(m[i]);
			free(m);
			exit_error(x, "malloc fail");
		}
	}
	x->map = m;
}

static void	fill_map(t_args *x, int w, int h, char **lines_p)
{
	int		r;
	int		c;
	char	*lines;
	int		**m;

	lines = *lines_p;
	m = x->map;
	r = -1;
	while (r < h)
	{
		c = -1;
		while (c < w)
		{
			if (lines_p[w * r + c] == '1')
				m[r][c] = WALL;
			else if (lines_p[w * r + c] == 'C')
				m[r][c] = COLLECTABLE;
			else if (lines_p[w * r + c] == 'E')
				m[r][c] = MAP_EXIT;
			else if (lines_p[w * r + c] == 'P')
				m[r][c] = PLAYER;
		}
	}
	free(*lines_p);
	*lines_p = NULL;
}

bool	parse(t_args *x, int fd)
{
	t_list	*last_node;
	char	*lines;
	bool	failed;

	if (parse_init(x, &last_node, fd, &failed))
		return (false);
	while (read_line(x, &lines, fd, &failed))
		;
	if (failed || x->w == 0 || !check_valid(x, lines))
	{
		free(lines);
		return (false);
	}
	create_map(x, x->w, x->h);
	fill_map(x, x->w, x->h, &lines);
	return (true);
}
