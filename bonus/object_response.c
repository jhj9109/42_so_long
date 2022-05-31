/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:54:42 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 16:58:56 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_collectable_response(t_args *x, t_object *collectable)
{
	if (collectable->status == 0)
	{
		collectable->status = 1;
		collectable->move = -1;
		x->collects--;
		printf("-------- earn collectable ---- remain: %d ---\n", x->collects);
	}
}

static void	_object_die(t_object *object)
{
	object->status = 1;
	object->move = -1;
}

static void	_between_player_object(t_args *x, t_object *player, int r, int c)
{
	t_object	*cur;

	cur = x->obj->next;
	while (cur)
	{
		if (cur->r == r && cur->c == c)
		{
			if (cur->type == OBJ_COLLECTABLE)
				_collectable_response(x, cur);
			if (cur->type == OBJ_ENEMY && cur->status == 0)
			{
				_object_die(player);
				x->finish = 2;
				cur->img_num = PLAYER_IMAGE_LENGTH - 1;
			}
		}
		cur = cur->next;
	}	
}

static void	_between_enemy_object(t_args *x, t_object *enemy, int r, int c)
{
	t_object	*cur;

	if (x->map[r][c])
	{
		_object_die(enemy);
		return ;
	}
	cur = x->obj->next;
	while (cur)
	{
		if (cur->r == r && cur->c == c && \
			cur->type != OBJ_PLAYER && \
			cur->oid != enemy->oid)
		{
			_object_die(enemy);
			return ;
		}
		cur = cur->next;
	}	
}

void	object_response(t_args *x, int r, int c)
{
	t_object	*cur;
	t_object	*player;

	player = x->obj;
	_between_player_object(x, player, r, c);
	cur = x->obj->next;
	while (cur)
	{
		if (cur->type == OBJ_ENEMY && cur->status == 0)
			_between_enemy_object(x, cur, cur->r, cur->c);
		cur = cur->next;
	}
}
