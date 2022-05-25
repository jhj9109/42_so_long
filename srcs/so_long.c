/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:37:57 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/25 19:49:50 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_on_close(t_args	*x)
{
	exit(EXIT_SUCCESS);
}


static int	_on_frame(t_args *x)
{
	static int frame = 0;
	int n = 4000;//1sec 12000
	
	frame++;
	if (frame == n)
	{
		frame = 0;
		t_object *cur = x->obj;
		while (cur)
		{
			if (cur->img_num == 1)
				cur->img_num = 2;
			else
				cur->img_num = 1;
			// cur->img_num = (cur->img_num + 1) % 3;
			cur = cur->next;
		}
		printf("frame: %d, img_num: %d\n", frame / n, x->obj->img_num);
		map_render(x);
	}
	return (0);
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
	x->win = mlx_new_window(x->mlx, x->w * TILE_SIZE, x->h * TILE_SIZE, "./so_long");
	if (!(x->win))
		exit_error(x, "mlx_new_window failed\n");
	map_init(x);
	map_render(x);
	mlx_loop_hook(x->mlx, &_on_frame, x);
	mlx_hook(x->win, X_EVENT_KEY_PRESS, 0, &on_key_press, x);
	mlx_hook(x->win, X_EVENT_CLOSE, 0, &_on_close, x);
	mlx_loop(x->mlx);
}