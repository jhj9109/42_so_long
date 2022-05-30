/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:32:06 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/30 21:03:58 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_init(t_args *x, int fd)
{
	char	*ret;

	ret = get_next_line(fd);
	if (ret == NULL)
		exit_invalid(x, "Error\n", "Invalid first line! Can't read first line!\n");
	if (ret[ft_strlen(ret) - 1] != '\n')
		exit_invalid(x, "Error\n", "Invalid first line! It didn't end with \\n\n");
	ret[ft_strlen(ret) - 1] = '\0';
	x->w = ft_strlen(ret);
	if (x->w == 0)
		exit_invalid(x, "Error\n", "Invalid first line! w is zero.\n");
	x->h = 1;
	x->lines = ret;
}

static bool	read_line(t_args *x, int fd)
{
	char	*ret;
	static	int a = -1;

	a++;
	ret = get_next_line(fd);
	if (ret == NULL)
		return (false);
	if (ret[ft_strlen(ret) - 1] == '\n')
		ret[ft_strlen(ret) - 1] = '\0';
	if (x->w != (int)ft_strlen(ret))
	{
		free(ret);
		exit_invalid(x, "Error\n", "Invalid line! width and line legnth doesn't match.\n");
	}
	x->lines = ft_strjoin(x->lines, ret);
	free(ret);
	if (x->lines == NULL)
		exit_error(x, "Malloc error at ft_strjoin.\n");
	x->h++;
	return (true);
}

static void	create_map(t_args *x, int w, int h)
{
	int	i;
	int	**map;

	map = ft_calloc(h, sizeof(int **));
	if (map == NULL)
		exit_error(x, "malloc fail at create_map\n");
	i = -1;
	while (++i < h)
	{
		map[i] = ft_calloc(w, sizeof(int *));
		if (map[i] == NULL)
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			exit_error(x, "malloc fail at create_map[i]\n");
		}
	}
	x->map = map;
}

static void	fill_map(t_args *x, int w, int h, char *lines)
{
	int		r;
	int		c;

	r = -1;
	while (++r < h)
	{
		c = -1;
		while (++c < w)
		{
			if (lines[w * r + c] == '1')
				x->map[r][c] = MAP_WALL;
			else if (lines[w * r + c] == 'E')
				x->map[r][c] = MAP_EXIT;
			else if (lines[w * r + c] == 'P')
			{
				x->obj->r = r;
				x->obj->c = c;
			}
			else if (lines[w * r + c] == 'C')
				ft_objlast(x->obj)->next = ft_objnew(x, OBJ_COLLECTABLE, r, c);
			else if (lines[w * r + c] == 'N')
				ft_objlast(x->obj)->next = ft_objnew(x, OBJ_ENEMY, r, c);
		}
	}
}

void	parse(t_args *x, char *file_name)
{	
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == ERROR)
		exit_error(NULL, "open file is failed");
	parse_init(x, fd);
	while (read_line(x, fd))
		;
	check_valid(x);
	create_map(x, x->w, x->h);
	fill_map(x, x->w, x->h, x->lines);
}
