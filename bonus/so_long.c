/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:37:57 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 17:07:21 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_on_close(t_args *x)
{
	free_args(x);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_args	*x;

	if (ac != 2)
		exit_invalid(NULL, "Error\n", "Program must have only one argument!\n");
	t_args_init(&x);
	parse(x, av[1]);
	x->mlx = mlx_init();
	if (!(x->mlx))
		exit_error(x, "mlx_init failed\n");
	x->win = mlx_new_window(x->mlx, \
							x->w * TILE_SIZE, x->h * TILE_SIZE, "./so_long");
	if (!(x->win))
		exit_error(x, "mlx_new_window failed\n");
	map_init(x);
	map_render(x);
	mlx_loop_hook(x->mlx, &on_frame, x);
	mlx_hook(x->win, X_EVENT_KEY_PRESS, 0, &on_key_press, x);
	mlx_hook(x->win, X_EVENT_CLOSE, 0, &_on_close, x);
	mlx_loop(x->mlx);
}
