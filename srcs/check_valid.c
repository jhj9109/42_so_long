/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:54:29 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 20:54:30 by hyeonjan         ###   ########.fr       */
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
		if (lines[i] != '0' || lines[n - i] != '0')
			return (false);
	i = 0;
	while (++i < h - 1)
		if (lines[w * i] != '0' || lines[w * i + w - 1] != '0')
			return (false);
	return (true);
}

static bool	check_map(t_args *x, int w, int h, char *lines)
{
	int	r;
	int	c;
	int cnt[3];// 0:출구, 1:수집품, 2:시작지점

	ft_memset(cnt, 0, 3 * sizeof(int));
	r = 0;
	while (++r < h)
	{
		c = 0;
		while (++c < w)
		{
			if (lines[w * r + c] == '0' || lines[w * r + c] == '1')
				continue ;
			else if (lines[w * r + c] == 'C')
				cnt[0] = cnt[0] + 1;
			else if (lines[w * r + c] == 'E')
				cnt[1] = cnt[1] + 1;
			else if (lines[w * r + c] == 'P')
				cnt[2] = cnt[2] + 1;
			else
				return (false);
		}
	}
	x->c = cnt[1];
	return (cnt[0] && cnt[1] & cnt[2] == 1);
}

bool	check_valid(t_args *x, char *lines)
{
	if (!is_walled_in(x->w, x->h, lines))
		return (false);
	if (!is_walled_in)
		return (false);
	return (true);
}
