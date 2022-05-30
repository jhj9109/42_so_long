/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:54:29 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/30 21:01:48 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_walled_in(int w, int h, char *lines)
{
	int	i;
	int	n;

	n = (int)ft_strlen(lines);
	i = -1;
	while (++i < w)
		if (lines[i] != '1' || lines[n - 1 - i] != '1')
			return (false);
	i = 0;
	while (++i < h - 1)
		if (lines[w * i] != '1' || lines[w * i + w - 1] != '1')
			return (false);
	return (true);
}

static void	call_error(t_args *x, int cnt[3])
{	
	if (cnt[0] == 0)
		exit_invalid(x, "Error\n", "Collectable at least one!\n");
	else if (cnt[1] == 0)
		exit_invalid(x, "Error\n", "Exit at least one!\n");
	else if (cnt[2] != 1)
		exit_invalid(x, "Error\n", "Player is only one!\n");
}

static void	check_map(t_args *x, int cnt[3], int r, int c)// 0:출구, 1:수집품, 2:시작지점
{	
	r = 0;
	while (++r < x->h)
	{
		c = 0;
		while (++c < x->w)
		{
			if (x->lines[x->w * r + c] == '0' || x->lines[x->w * r + c] == '1')
				continue ;
			else if (x->lines[x->w * r + c] == 'C')
				cnt[0] = cnt[0] + 1;
			else if (x->lines[x->w * r + c] == 'E')
				cnt[1] = cnt[1] + 1;
			else if (x->lines[x->w * r + c] == 'P')
				cnt[2] = cnt[2] + 1;
			else if (x->lines[x->w * r + c] == 'N')
				continue ;
			else
				exit_invalid(x, "Error\n", "Invalid element in map!\n");
		}
	}
}

void	check_valid(t_args *x)
{
	int	cnt[3];

	if (!is_walled_in(x->w, x->h, x->lines))
		exit_invalid(x, "Error\n", "map isn't arround wall!\n");
	ft_memset(cnt, 0, 3 * sizeof(int));
	check_map(x, cnt, 0, 0);
	x->collects = cnt[1];
	call_error(x, cnt);
}
