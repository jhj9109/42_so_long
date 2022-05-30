#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		percent;
	int		rgb[3];


	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (get_t_int(color) == 0)
	{
		rgb[0] = get_r_int(*(int*)dst) * (100 - percent) / 100 + \
				get_r_int(color) * percent / 100; 
		rgb[1] = get_g_int(*(int*)dst) * (100 - percent) / 100 + \
				get_g_int(color) * percent / 100; 
		rgb[2] = get_b_int(*(int*)dst) * (100 - percent) / 100 + \
				get_b_int(color) * percent / 100;
		*(unsigned int*)dst = create_trgb_int(
			get_t_int(color),
			get_r_int(color),
			get_g_int(color),
			get_b_int(color)
		);
	}
	// *(unsigned int*)dst = color;
	// percent = (0xFF - get_t_int(color)) * 100 / 0xFF;//0 -> 100% 출력
	// if (percent)
	// {
	// 	rgb[0] = get_r_int(*(int*)dst) * (100 - percent) / 100 + \
	// 			get_r_int(color) * percent / 100; 
	// 	rgb[1] = get_g_int(*(int*)dst) * (100 - percent) / 100 + \
	// 			get_g_int(color) * percent / 100; 
	// 	rgb[2] = get_b_int(*(int*)dst) * (100 - percent) / 100 + \
	// 			get_b_int(color) * percent / 100;
	// 	*(unsigned int*)dst = create_trgb_int(get_t_int(color), rgb[0], rgb[1], rgb[2]);
	// }
}


/*
typedef struct	mlx_img_list_s
{
  int			width;
  int			height;
  char			*buffer;
  GLfloat		vertexes[8];
  struct mlx_img_list_s	*next;
} mlx_img_list_t;
*/