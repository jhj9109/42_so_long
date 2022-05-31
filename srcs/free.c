/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:00:01 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 20:34:26 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	j_free(void *p)
{
	if (p)
		free(p);
}

void	_free_objects(t_object *head)
{
	t_object	*cur;
	t_object	*temp;

	cur = head;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		j_free(temp);
	}
}

void	free_args(t_args *x)
{
	int	**map;
	int	i;

	j_free(x->lines);
	j_free(x->img1);
	j_free(x->img2);
	map = x->map;
	if (map)
	{
		i = -1;
		while (++i < x->h)
			j_free(map[i]);
		j_free(map);
	}
	_free_objects(x->obj);
	j_free(x);
}
