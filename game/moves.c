/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:11:27 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/19 14:38:01 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	move_down(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;

	posy = floor(cub->pos.y + cub->dir.y * moveSpeed);
	posx = floor(cub->pos.x + cub->dir.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->dir.y * moveSpeed);
	cub->pos.x += (cub->dir.x * moveSpeed);
}

void	move_forward(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;

	posy = floor(cub->pos.y - cub->dir.y * moveSpeed);
	posx = floor(cub->pos.x - cub->dir.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->dir.y * moveSpeed);
	cub->pos.x -= (cub->dir.x * moveSpeed);
}

void	move_left(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;

	posy = floor(cub->pos.y - cub->plane.y * moveSpeed);
	posx = floor(cub->pos.x - cub->plane.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->plane.y * moveSpeed);
	cub->pos.x -= (cub->plane.x * moveSpeed);
}

void	move_right(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;


	posy = floor(cub->pos.y + cub->plane.y * moveSpeed);
	posx = floor(cub->pos.x + cub->plane.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->plane.y * moveSpeed);
	cub->pos.x += (cub->plane.x * moveSpeed);
}

int	keycode(int key, t_cub *cub)
{
	if (key == ESC)
		close_window(cub);
	if (key == D)
		move_right(cub);
	if (key == A)
		move_left(cub);
	if (key == S)
		move_forward(cub);
	if (key == W)
		move_down(cub);
	if (key == RIGHT)
		rotate_right(cub);
	if (key == LEFT)
		rotate_left(cub);
	return (0);
}
