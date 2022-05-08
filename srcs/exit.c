/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:55:36 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 21:55:38 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_args *x, char *s)
{
	perror(s);
	free_args(x);
	exit(EXIT_FAILURE);
}

void	exit_invalid(t_args *x, char *s1, char *s2)
{
	if (s1)
		ft_putstr_fd(s1, STDERR_FILENO);
	if (s2)
		ft_putstr_fd(s2, STDERR_FILENO);
	free_args(x);
	exit(EXIT_FAILURE);
}

void	exit_valid(t_args *x)
{
	free_args(x);
	exit(EXIT_SUCCESS);
}

