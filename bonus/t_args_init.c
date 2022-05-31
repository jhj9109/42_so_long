/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_args_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:05:38 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/31 17:07:24 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	*x = ret;
}
