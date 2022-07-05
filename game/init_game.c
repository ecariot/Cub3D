/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:40:17 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/05 12:38:21 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../mlx_linux/mlx.h"

// void	init_texture(t_cub *cub)
// {
// 	// cub->walls.img = mlx_xpm_file_to_image(cub->mlx,
// 	// 	 "../textures/redbrick_1.xpm", &cub->walls.width, &cub->walls.height);
// 	// if (!cub->walls.img)
// 	// 	return_error("Missing texture\n");

// }

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

int	draw_window(t_cub *cub)
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
	cub->screen.addr = mlx_get_data_addr(cub->mlx, &cub->screen.bits_per_pixel, &cub->screen.line_len, &cub->screen.endian);
	return (0);
}
