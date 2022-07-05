/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:31:20 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/05 10:32:36 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void ft_init_texture(t_data *data)
{
	data->texture.floor_r = 0;
	data->texture.floor_g = 0;
	data->texture.floor_b = 0;
	data->texture.ceiling_r = 0;
	data->texture.ceiling_g = 0;
	data->texture.ceiling_b = 0;
	data->texture.north = NULL;
	data->texture.south = NULL;
	data->texture.east = NULL;
	data->texture.west = NULL;
}

void ft_init_cub(t_data *data)
{
	data->cub.line = 0;
	data->cub.col = 0;
	data->cub.width = 0;
	data->cub.dirY = 0;
	data->cub.dirX = 0;
	data->cub.posY = 0;
	data->cub.posX = 0;
	data->cub.map = NULL;
}
