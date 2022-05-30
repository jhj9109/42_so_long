#include "so_long.h"

static void	_end_game(t_args *x)
{
	printf("end_game by press esc\n");
	exit_valid(x);
}

int	on_key_press(int keycode, t_args *x)
{
	char		buf[14];
	t_object	*player;

	buf[13] = '\0';
	player = x->obj;
	if (keycode == KEY_ESC)
		_end_game(x);
	if (!x->finish)
	{
		if (keycode == KEY_W)
		move_trigger(x, player, UP);
	else if (keycode == KEY_A)
		move_trigger(x, player, LEFT);
	else if (keycode == KEY_S)
		move_trigger(x, player, DOWN);
	else if (keycode == KEY_D)
		move_trigger(x, player, RIGHT);
	}
	// printf("keycode:%d && r,c: (%d,%d), col:%d, moved:%d\n",
	// 	keycode, player->r, player->c, x->collects, x->moved);
	map_render(x);
	return (0);
}