/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:56:41 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/30 21:03:17 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_enemy_render(t_args *x, t_object *enemy)
{
	int	n;

	if (enemy->move > 0)
		n = enemy->move;
	else
		n = enemy->img_num;
	mlx_put_image_to_window(
		x->mlx,
		x->win,
		x->enemy_img[n],
		enemy->c * TILE_SIZE,
		enemy->r * TILE_SIZE);
	// if (enemy->move == 0)
	// 	enemy->img_num = (enemy->img_num + 1) % 4;
	// 	enemy->move = (enemy->move + 1) % ENEMY_IMAGE_LENGTH;
	// else
	// 	enemy->img_num = (enemy->img_num + 1) % 4;
}

static void	_player_render(t_args *x, t_object *player)
{
	int	n;

	if (player->move > 0)
		n = player->move;
	else
		n = player->img_num;
	printf("p: %d\n", n);
	// printf("player: move:%d, img_num:%d, %d\n", player->move, player->img_num, player->move || player->img_num);
	mlx_put_image_to_window(
		x->mlx,
		x->win,
		x->player_img[n],
		player->c * TILE_SIZE,
		player->r * TILE_SIZE);
	// if (player->move == 0)
	// 	player->img_num = (player->img_num + 1) % 6;
	// 	player->move = (player->move + 1) % PLAYER_IMAGE_LENGTH;
	// else
	// 	player->img_num = (player->img_num + 1) % 6;
}

static void	_collectable_render(t_args *x, t_object *collectable)
{
	int	n;

	if (collectable->move > 0)
		n = collectable->move;
	else
		n = collectable->img_num;
	if (collectable->move)
		printf("\n--------------col_move:%d => %d\n", collectable->move, n);
	printf("\ncol_move:%d => %d\n", collectable->move, n);
	// printf("\ncol: (move:%d, img_num:%d) => %d\n", collectable->move, collectable->img_num, n);
	mlx_put_image_to_window(
		x->mlx,
		x->win,
		x->collectable_img[n],
		collectable->c * TILE_SIZE,
		collectable->r * TILE_SIZE);
	// if (collectable->move > 0)
	// 	collectable->move = (collectable->move + 1) % COLLECTABLE_IMAGE_LENGTH;
}

void	object_render(t_args *x)
{
	t_object	*cur;

	cur = x->obj->next;
	while (cur)
	{
		if (cur->type == OBJ_ENEMY && cur->status != 2)
			_enemy_render(x, cur);
		cur = cur->next;
	}
	_player_render(x, x->obj);
	cur = x->obj->next;
	while (cur)
	{
		if (cur->type == OBJ_COLLECTABLE)
			_collectable_render(x, cur);
		cur = cur->next;
	}
}
