/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:37:57 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 19:38:00 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	//key => x 클릭에 의한 종료도 시그널 존재.
	/*
	'0': empty
	'1': wall
	'C': collectible
	'E': map exit
	'P': player’s starting position.

	mlx_loop_hook 함수 인자로 printf정도만 하는 함수 포인터를 넘겨주시고
	구동해보시면 애니메이션을 어떻게 넣어야할지 감이 오실거에용

	mlx_hook에 key_exit
	key_press로 esc
	mlx_hook(win_ptr, 17, 0, (실행될함수), (넘겨줄인자값));

	The X server can report DestroyNotify events to clients wanting information
	about which windows are destroyed.
	The X server generates this event whenever a client application destroys
	a window by calling XDestroyWindow() or XDestroySubwindows().
	*/
	//mlx_destory
}