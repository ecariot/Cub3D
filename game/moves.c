/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:46:30 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 14:12:44 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	move_down(t_cub *cub)
{
	int		posy;
	int		posx;
	double	move_speed;

	move_speed = 0.1;
	posy = floor(cub->pos.y + cub->dir.y * move_speed);
	posx = floor(cub->pos.x + cub->dir.x * move_speed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->dir.y * move_speed);
	cub->pos.x += (cub->dir.x * move_speed);
}

void	move_forward(t_cub *cub)
{
	int		posy;
	int		posx;
	double	move_speed;

	move_speed = 0.1;
	posy = floor(cub->pos.y - cub->dir.y * move_speed);
	posx = floor(cub->pos.x - cub->dir.x * move_speed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->dir.y * move_speed);
	cub->pos.x -= (cub->dir.x * move_speed);
}

void	move_left(t_cub *cub)
{
	int		posy;
	int		posx;
	double	move_speed;

	move_speed = 0.1;
	posy = floor(cub->pos.y - cub->plane.y * move_speed);
	posx = floor(cub->pos.x - cub->plane.x * move_speed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->plane.y * move_speed);
	cub->pos.x -= (cub->plane.x * move_speed);
}

void	move_right(t_cub *cub)
{
	int		posy;
	int		posx;
	double	move_speed;

	move_speed = 0.1;
	posy = floor(cub->pos.y + cub->plane.y * move_speed);
	posx = floor(cub->pos.x + cub->plane.x * move_speed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->plane.y * move_speed);
	cub->pos.x += (cub->plane.x * move_speed);
}

void	rotate_left(t_cub *cub)
{
	double	tmp;
	double	tmp_plane;
	double	rot_speed;

	rot_speed = (20.0 / 1000.0) * 3.0;
	tmp = cub->dir.x;
	cub->dir.x = cub->dir.x * cos(-rot_speed) - cub->dir.y * sin(-rot_speed);
	cub->dir.y = tmp * sin(-rot_speed) + cub->dir.y * cos(-rot_speed);
	tmp_plane = cub->plane.x;
	cub->plane.x = cub->plane.x * cos(-rot_speed)
		- cub->plane.y * sin(-rot_speed);
	cub->plane.y = tmp_plane * sin(-rot_speed) + cub->plane.y * cos(-rot_speed);
}
