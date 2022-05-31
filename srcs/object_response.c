/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:54:42 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 21:13:22 by hyeonjan         ###   ########.fr       */
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

static void	_between_player_object(t_args *x, int r, int c)
{
	t_object	*cur;

	cur = x->obj->next;
	while (cur)
	{
		if (cur->r == r && cur->c == c)
		{
			if (cur->type == OBJ_COLLECTABLE)
				_collectable_response(x, cur);
		}
		cur = cur->next;
	}	
}

void	object_response(t_args *x, int r, int c)
{
	_between_player_object(x, r, c);
}
