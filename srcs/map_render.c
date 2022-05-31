/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:49:36 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 21:21:06 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_tile_render(t_args *x, int val, int r, int c)
{
	if (val != MAP_EXIT)
		mlx_put_image_to_window(x->mlx, x->win, (x->tile_img)[val], \
								c * TILE_SIZE, r * TILE_SIZE);
	else if (x->collects)
		mlx_put_image_to_window(x->mlx, x->win, (x->tile_img)[MAP_EXIT], \
								c * TILE_SIZE, r * TILE_SIZE);
	else
		mlx_put_image_to_window(x->mlx, x->win, (x->tile_img)[MAP_EXIT_OPEN], \
								c * TILE_SIZE, r * TILE_SIZE);
}

static void	_background_render(t_args *x)
{
	int	r;
	int	c;

	r = -1;
	while (++r < x->h)
	{
		c = -1;
		while (++c < x->w)
			_tile_render(x, (x->map)[r][c], r, c);
	}
}

void	map_render(t_args *x)
{
	_background_render(x);
	object_render(x);
}
