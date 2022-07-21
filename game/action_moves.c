/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:48:43 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 13:49:45 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	action_key(t_cub *cub)
{
	if (cub->right == 1)
		move_right(cub);
	if (cub->left == 1)
		move_left(cub);
	if (cub->forward == 1)
		move_forward(cub);
	if (cub->down == 1)
		move_down(cub);
	if (cub->rotate_r)
		rotate_right(cub);
	if (cub->rotate_l)
		rotate_left(cub);
}

int	keycode(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	if (key == D)
		data->cub.right = 1;
	if (key == A)
		data->cub.left = 1;
	if (key == S)
		data->cub.forward = 1;
	if (key == W)
		data->cub.down = 1;
	if (key == RIGHT)
		data->cub.rotate_r = 1;
	if (key == LEFT)
		data->cub.rotate_l = 1;
	return (1);
}

int	keycode_zero(int key, t_data *data)
{
	if (key == D)
		data->cub.right = 0;
	if (key == A)
		data->cub.left = 0;
	if (key == S)
		data->cub.forward = 0;
	if (key == W)
		data->cub.down = 0;
	if (key == RIGHT)
		data->cub.rotate_r = 0;
	if (key == LEFT)
		data->cub.rotate_l = 0;
	if (key == ESC)
		close_window(data);
	return (1);
}
