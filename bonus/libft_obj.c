#include "so_long.h"

t_object	*ft_objlast(t_object *head)
{
	t_object	*cur;

	cur = head;
	if (cur == NULL)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}

t_object	*ft_objnew(t_args *x, int type, int r, int c)
{
	static int	oid = 1;
	t_object	*new_obj;

	new_obj = ft_calloc(1, sizeof(t_object));
	if (new_obj == NULL)
		exit_error(x, "Malloc error at ft_objnew\n");
	new_obj->type = type;
	new_obj->r = r;
	new_obj->c = c;
	new_obj->oid = oid++;
	return (new_obj);
}
