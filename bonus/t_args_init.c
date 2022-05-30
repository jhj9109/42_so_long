#include "so_long.h"

void	t_args_init(t_args **x)
{
	t_args	*ret;

	*x = NULL;
	ret = ft_calloc(1, sizeof(t_args));
	if (ret == NULL)
		exit_error(NULL, "malloc for t_args is failed");
	ret->obj = ft_calloc(1, sizeof(t_object));
	if (!(ret->obj))
		exit_error(ret, "malloc for t_object is failed");
	// ret->player = ret->obj;
	*x = ret;
}
