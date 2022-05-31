/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:56:41 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 21:08:56 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_get_img_index(t_object *obj)
{
	if (obj->move > 0)
		return (obj->move);
	return (obj->img_num);
}

static void	_player_render(t_args *x, t_object *player)
{
	mlx_put_image_to_window(
		x->mlx,
		x->win,
		x->player_img[_get_img_index(player)],
		player->c * TILE_SIZE,
		player->r * TILE_SIZE);
}

static void	_collectable_render(t_args *x, t_object *collectable)
{
	mlx_put_image_to_window(
		x->mlx,
		x->win,
		x->collectable_img[_get_img_index(collectable)],
		collectable->c * TILE_SIZE,
		collectable->r * TILE_SIZE);
}

void	object_render(t_args *x)
{
	t_object	*cur;

	_player_render(x, x->obj);
	cur = x->obj->next;
	while (cur)
	{
		if (cur->type == OBJ_COLLECTABLE)
			_collectable_render(x, cur);
		cur = cur->next;
	}
}
