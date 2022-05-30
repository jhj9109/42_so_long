/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:55:36 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/30 21:16:14 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_args *x, char *s)
{
	perror(s);
	if (x)
		free_args(x);
	exit(EXIT_FAILURE);
}

void	exit_invalid(t_args *x, char *s1, char *s2)
{
	if (s1)
		ft_putstr_fd(s1, STDERR_FILENO);
	if (s2)
		ft_putstr_fd(s2, STDERR_FILENO);
	if (x)
		free_args(x);
	exit(EXIT_FAILURE);
}

void	exit_valid(t_args *x)
{
	free_args(x);
	exit(EXIT_SUCCESS);
}
