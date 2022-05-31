/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:00:15 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 17:40:04 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_obj_push_back(t_args *x, int type, int r, int c)
{
	t_object	*cur;
	t_object	*new_node;

	new_node = ft_objnew(x, type, r, c);
	cur = x->obj;
	if (cur == NULL)
		x->obj = new_node;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
	}
}
