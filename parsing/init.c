/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:57:48 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 16:10:41 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_init_texture(t_data *data)
{
	data->texture.floor_r = -1;
	data->texture.floor_g = -1;
	data->texture.floor_b = -1;
	data->texture.ceiling_r = -1;
	data->texture.ceiling_g = -1;
	data->texture.ceiling_b = -1;
	data->texture.north = NULL;
	data->texture.south = NULL;
	data->texture.east = NULL;
	data->texture.west = NULL;
	data->texture.full = 0;
}

int	ft_init_cub_bis(t_data *data)
{
	data->cub.step.x = 0.0;
	data->cub.step.y = 0.0;
	data->cub.tab.x = 0.0;
	data->cub.tab.y = 0.0;
	data->cub.camerax = 0;
	data->cub.wallx = 0.0;
	data->cub.hit = 0;
	data->cub.map = NULL;
	data->cub.side_wall = 0;
	data->cub.rotate_r = 0;
	data->cub.rotate_l = 0;
	data->cub.left = 0;
	data->cub.right = 0;
	data->cub.down = 0;
	data->cub.forward = 0;
	return (1);
}

int	ft_init_cub(t_data *data)
{
	data->cub.player = '\0';
	data->cub.line = 0;
	data->cub.col = 0;
	data->cub.win_width = 0;
	data->cub.win_height = 0;
	data->cub.dir.x = 0.0;
	data->cub.dir.y = 0.0;
	data->cub.pos.x = 0.0;
	data->cub.pos.y = 0.0;
	data->cub.plane.x = 0.0;
	data->cub.plane.y = 0.0;
	data->cub.raydir.x = 0.0;
	data->cub.raydir.y = 0.0;
	data->cub.sidedist.x = 0.0;
	data->cub.sidedist.y = 0.0;
	return (ft_init_cub_bis(data));
}

void	init_player_e(t_cub *cub)
{
	cub->dir.x = 1.0;
	cub->dir.y = 0.0;
	cub->plane.y = 0.66;
}

void	init_player(t_cub *cub)
{
	if (cub->player == 'N')
	{
		cub->dir.x = 0.0;
		cub->dir.y = -1.0;
		cub->plane.x = 0.66;
	}
	if (cub->player == 'S')
	{
		cub->dir.x = 0.0;
		cub->dir.y = 1.0;
		cub->plane.x = -0.66;
	}
	if (cub->player == 'W')
	{
		cub->dir.x = -1.0;
		cub->dir.y = 0.0;
		cub->plane.y = -0.66;
	}
	if (cub->player == 'E')
		init_player_e(cub);
}
