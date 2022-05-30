#include "so_long.h"

static void	_move_ctrl(t_object *obj)
{
	if (obj->move == -1)
	{
		if (obj->type == OBJ_PLAYER)
			obj->move = 6;
		else if (obj->type == OBJ_ENEMY)
			obj->move = 4;
		else if (obj->type == OBJ_COLLECTABLE)
			obj->move = 1;
	}
	else if (obj->move > 0)
	{
		if (obj->type == OBJ_PLAYER)
		{
			obj->move = (obj->move + 1) % PLAYER_IMAGE_LENGTH;
			if (obj->move == 0 && obj->status == 1)
			{
				obj->status = 2;
				obj->img_num = PLAYER_IMAGE_LENGTH - 1;
			}
		}
		else if (obj->type == OBJ_ENEMY)
		{
			obj->move = (obj->move + 1) % ENEMY_IMAGE_LENGTH;
			if (obj->move == 0 && obj->status == 1)
				obj->status = 2;
		}
		else if (obj->type == OBJ_COLLECTABLE)
		{
			obj->img_num = COLLECTABLE_IMAGE_LENGTH - 1;
			obj->move = (obj->move + 1) % COLLECTABLE_IMAGE_LENGTH;
		}
	}
}

static void	_img_num_ctrl(t_object *obj)
{
	if (obj->type == OBJ_PLAYER && obj->status != 2)
		obj->img_num = (obj->img_num + 1) % 6;
	else if (obj->type == OBJ_ENEMY)
	{
		obj->img_num = (obj->img_num + 1) % 4;
	}
}

int	on_frame(t_args *x)
{
	static int frame = 0;
	int n = 6000;//1sec 12000
	t_object *cur;
	
	// if (x->finish)
	// 	return (0);
	frame++;
	if (frame == n)
	{
		frame = 0;
		cur = x->obj;
		while (cur)
		{
			if (cur->move)
				_move_ctrl(cur);
			else
				_img_num_ctrl(cur);
			cur = cur->next;
		}
		// printf("frame: %d, img_num: %d\n", frame / n, x->obj->img_num);
		map_render(x);
	}
	return (0);
}
