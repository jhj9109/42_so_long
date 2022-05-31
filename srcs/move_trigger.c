/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_trigger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:50:56 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 21:21:38 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_dr[4] = {-1, 0, 1, 0};
static int	g_dc[4] = {0, 1, 0, -1};

static bool	_can_move(t_args *x, int r, int c, int direction)
{
	int			nr;
	int			nc;

	nr = r + g_dr[direction];
	nc = c + g_dc[direction];
	if (x->map[nr][nc] == MAP_WALL ||
		(x->map[nr][nc] == MAP_EXIT && x->collects))
		return (false);
	return (true);
}

static void	_player_move(t_args *x, t_object *player, int direction)
{
	player->r = player->r + g_dr[direction];
	player->c = player->c + g_dc[direction];
	x->moved++;
	printf("moved: %d\n", x->moved);
	if (x->moved < 0)
		x->moved = 0;
}

void	move_trigger(t_args *x, t_object *player, int direction)
{
	if (_can_move(x, player->r, player->c, direction))
	{
		_player_move(x, x->obj, direction);
		if (x->map[player->r][player->c] == MAP_EXIT)
		{
			printf("you win! moved: %d\npress esc to exit.\n", x->moved);
			x->finish = 1;
			return ;
		}
		object_response(x, player->r, player->c);
	}
}
