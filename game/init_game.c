/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:24:53 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/05 13:53:23 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_struct(t_cub *cub)
{
	cub->map = 0;
	cub->posX = 0;
	cub->posY = 0;
	cub->dirX = 0;
	cub->dirY = 0;
	cub->w = 0;
	cub->h = 0;
}

int	draw_window(t_cub *cub, t_texture *texture)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return_error("test");
	cub->mlx_win = mlx_new_window(cub->mlx, 1064, 640, "Mbascu le plus beau poisson de l'aquarium");
	if (!cub->mlx_win)
		return_error("pas ok");
	cub->screen.img = mlx_new_image(cub->mlx, 1064, 640);
	if (!cub->screen.img)
		return_error("test1");
	cub->screen.addr = mlx_get_data_addr(cub->mlx,
		&cub->screen.bits_per_pixel, &cub->screen.line_len, &cub->screen.endian);
	texture->north = mlx_xpm_file_to_image(cub->mlx,
		"../textures/redbrick_1.xpm", texture->width, texture->height);
	return (0);
}
