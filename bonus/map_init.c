/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:45:59 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 17:00:35 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*g_tile_img_filenames[TILE_IMAGE_LENGTH] = {
	"xpm/tile_grass.xpm",
	"xpm/tile_wooden.xpm",
	"xpm/tile_door_close.xpm",
	"xpm/tile_door_open.xpm",
};
static char	*g_player_img__filenames[PLAYER_IMAGE_LENGTH] = {
	"xpm/player_in_place_00.xpm",
	"xpm/player_in_place_01.xpm",
	"xpm/player_in_place_02.xpm",
	"xpm/player_in_place_03.xpm",
	"xpm/player_in_place_04.xpm",
	"xpm/player_in_place_05.xpm",
	"xpm/player_die_00.xpm",
	"xpm/player_die_01.xpm",
	"xpm/player_die_02.xpm",
};
static char	*g_collectable_img_filenames[COLLECTABLE_IMAGE_LENGTH] = {
	"xpm/chest_open_00.xpm",
	"xpm/chest_open_01.xpm",
	"xpm/chest_open_02.xpm",
	"xpm/chest_open_03.xpm",
};
static char	*g_enemy_img_filenames[ENEMY_IMAGE_LENGTH] = {
	"xpm/slime_in_place_00.xpm",
	"xpm/slime_in_place_01.xpm",
	"xpm/slime_in_place_02.xpm",
	"xpm/slime_in_place_03.xpm",
	"xpm/slime_die_00.xpm",
	"xpm/slime_die_01.xpm",
	"xpm/slime_die_02.xpm",
	"xpm/slime_die_03.xpm",
	"xpm/slime_die_04.xpm",
};

static void	_load_img(t_args *x, char **filenames, void **loaded_img, int len)
{
	int	w;
	int	h;
	int	i;

	i = -1;
	while (++i < len)
	{
		loaded_img[i] = mlx_xpm_file_to_image(x->mlx, filenames[i], &w, &h);
		if (loaded_img[i] == NULL)
			exit_error(x, "fail load to loaded_img\n");
		if (w != TILE_SIZE || h != TILE_SIZE)
			exit_invalid(x, "loaded_img is invalid\n", NULL);
	}
}

void	map_init(t_args *x)
{
	_load_img(x, g_tile_img_filenames, x->tile_img, TILE_IMAGE_LENGTH);
	_load_img(x, g_player_img__filenames, x->player_img, PLAYER_IMAGE_LENGTH);
	_load_img(x, g_collectable_img_filenames, x->collectable_img, \
				COLLECTABLE_IMAGE_LENGTH);
	_load_img(x, g_enemy_img_filenames, x->enemy_img, ENEMY_IMAGE_LENGTH);
}
