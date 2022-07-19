/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:11:27 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/13 17:05:58 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_next_step(int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' && x == j && y == i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	move_down(t_cub *cub)
{
	int posy;
	int posx;

	posy = floor(cub->pos.y + cub->dir.y * 0.1);
	posx = floor(cub->pos.x + cub->dir.x * 0.1);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->dir.y * 0.1);
	cub->pos.x += (cub->dir.x * 0.1);
}

void	move_forward(t_cub *cub)
{
	int posy;
	int posx;

	posy = floor(cub->pos.y - cub->dir.y * 0.1);
	posx = floor(cub->pos.x - cub->dir.x * 0.1);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->dir.y * 0.1);
	cub->pos.x -= (cub->dir.x * 0.1);
}

void	move_left(t_cub *cub)
{
	int posy;
	int posx;

	posy = floor(cub->pos.y - cub->plane.y * 0.1);
	posx = floor(cub->pos.x - cub->plane.x * 0.1);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->plane.y * 0.1);
	cub->pos.x -= (cub->plane.x * 0.1);
}

void	move_right(t_cub *cub)
{
	int posy;
	int posx;

	posy = floor(cub->pos.y + cub->plane.y * 0.1);
	posx = floor(cub->pos.x + cub->plane.x * 0.1);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->plane.y * 0.1);
	cub->pos.x += (cub->plane.x * 0.1);
}

int	keycode(int key, t_cub *cub)
{
	if (key == 65307)
		close_window(cub);
	if (key == 100)
		move_right(cub);
	if (key == 97)
		move_left(cub);
	if (key == 115)
		move_forward(cub);
	if (key == 119)
		move_down(cub);
	if (key == 65363)
		rotate_right(cub);
	if (key == 65361)
		rotate_left(cub);
	return (0);
}
