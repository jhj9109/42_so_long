/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:09:56 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 18:00:14 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_ctrl_player(t_object *player)
{
	if (player->move == 0 && player->status != 2)
		player->img_num = (player->img_num + 1) % 6;
	else if (player->move == -1)
		player->move = 6;
	else if (player->move > 0)
	{
		player->move = (player->move + 1) % PLAYER_IMAGE_LENGTH;
		if (player->move == 0 && player->status == 1)
		{
			player->status = 2;
			player->img_num = PLAYER_IMAGE_LENGTH - 1;
		}
	}
}

static void	_ctrl_collectable(t_object *collectable)
{
	if (collectable->move == -1)
		collectable->move = 1;
	else if (collectable->move > 0)
	{
		collectable->img_num = COLLECTABLE_IMAGE_LENGTH - 1;
		collectable->move = (collectable->move + 1) % COLLECTABLE_IMAGE_LENGTH;
	}
}

static void	_ctrl_enemy(t_object *enemy)
{
	if (enemy->move == 0)
		enemy->img_num = (enemy->img_num + 1) % 4;
	else if (enemy->move == -1)
		enemy->move = 4;
	else if (enemy->move > 0)
	{
		enemy->move = (enemy->move + 1) % ENEMY_IMAGE_LENGTH;
		if (enemy->move == 0 && enemy->status == 1)
			enemy->status = 2;
	}
}

/* 1sec => 12000 */
int	on_frame(t_args *x)
{
	static int	frame = 0;
	static int	n = 1000;
	t_object	*cur;

	frame++;
	if (frame == n)
	{
		frame = 0;
		cur = x->obj;
		while (cur)
		{
			if (cur->type == OBJ_COLLECTABLE)
				_ctrl_collectable(cur);
			else if (cur->type == OBJ_ENEMY)
				_ctrl_enemy(cur);
			else if (cur->type == OBJ_PLAYER)
				_ctrl_player(cur);
			cur = cur->next;
		}
		map_render(x);
	}
	return (0);
}
