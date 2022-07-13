/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:11:27 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/13 12:27:39 by emcariot         ###   ########.fr       */
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

int	move_right(t_cub *cub)
{
	int	move;

	move = check_next_step(cub->pos.x, cub->pos.y + 1, cub->map);
	if (move == 1)
		return (0);
	cub->pos.y += 0.5;
	return (1);
}

int	move_left(t_cub *cub)
{
	int	move;

	move = check_next_step(cub->pos.x, cub->pos.y - 1, cub->map);
	if (move == 1)
		return (0);
	cub->pos.y -= 0.5;
	return (1);
}

int	move_forward(t_cub *cub)
{
	int	move;

	move = check_next_step(cub->pos.x - 1, cub->pos.y, cub->map);
	if (move == 1)
		return (0);
	cub->pos.x -= 0.5;
	return (1);
}

int	move_down(t_cub *cub)
{
	int	move;

	move = check_next_step(cub->pos.x + 1, cub->pos.y, cub->map);
	if (move == 1)
		return (0);
	cub->pos.x += 0.5;
	return (1);
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
	return (0);
}
