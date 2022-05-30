#include "so_long.h"

static void	_tile_render(t_args *x, int val, int r, int c)
{
	// if (val < 0 || val >= IMAGE_LENGTH)
	// 	exit_invalid(x, "Error\n", "Invalid get_loaded_img() request.\n");
	if (val == MAP_EXIT && x->collects)
		mlx_put_image_to_window(x->mlx, x->win, (x->tile_img)[MAP_EXIT], c * TILE_SIZE, r * TILE_SIZE);
	else if (val == MAP_EXIT && !x->collects)
		mlx_put_image_to_window(x->mlx, x->win, (x->tile_img)[MAP_EXIT_OPEN], c * TILE_SIZE, r * TILE_SIZE);
	else
		mlx_put_image_to_window(x->mlx, x->win, (x->tile_img)[val], c * TILE_SIZE, r * TILE_SIZE);
}

static void _background_render(t_args *x)
{
	int r;
	int c;

	r = -1;
	while (++r < x->h)
	{
		c = -1;
		while (++c < x->w)
			_tile_render(x, (x->map)[r][c], r, c);
	}
}

void _moved_render(t_args *x)
{
	char	buf[14];

	buf[13] = '\0';
	mlx_string_put(
		x->mlx,
		x->win,
		0,
		0,
		0xffffff,
		ft_itoa(
			&buf[13],
			x->moved));
}

void map_render(t_args *x)
{
	static char	*s[2] = {
		"you win!. press esc to exit!",
		"you lose!. press esc to exit!",
	};
	_background_render(x);
	object_render(x);
	_moved_render(x);
	if (x->finish)
		mlx_string_put(x->mlx, x->win,
			0, (x->h - 1) * TILE_SIZE,
			0xffffff, s[x->finish - 1]);
}
