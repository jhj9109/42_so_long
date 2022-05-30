#include "so_long.h"

void	j_free(void *p)
{
	if (p)
		free(p);
}

void	free_args(t_args *x)
{
	int			**map;
	int	i;

	j_free(x->lines);
	j_free(x->img1);
	j_free(x->img2);
	map = x->map;
	if (map)
	{
		i = -1;
		while (++i < x->h)
			free(map[i]);
		free(map);
	}
	free(x);
}
