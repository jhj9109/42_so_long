#include "so_long.h"

void	my_mlx_pixel_get_info(t_data *data, int x, int y, int trgb[4])
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	trgb[0] = get_t_int(*(int*)dst);
	trgb[1] = get_r_int(*(int*)dst);
	trgb[2] = get_g_int(*(int*)dst);
	trgb[3] = get_b_int(*(int*)dst);
}