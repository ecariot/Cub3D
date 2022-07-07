/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:24:53 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/07 15:14:54 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void draw_map(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->w_no.img, 600, 600);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->w_so.img, 50, 50);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->w_ea.img, 200, 200);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->w_we.img, 400, 400);
}

int	put_img(t_cub *cub)
{
	init_raycasting(cub);
	// draw_map(cub);
	return (1);
}

int	draw_window(t_cub *cub, t_data *data)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return_error("Erreur");
	mlx_get_screen_size(cub->mlx, &cub->win_width, &cub->win_height);
	cub->mlx_win = mlx_new_window(cub->mlx,  cub->win_width, cub->win_height, "Cub3d");
	cub->screen.img = mlx_new_image(cub->mlx, cub->win_width, cub->win_height);
	cub->screen.addr = mlx_get_data_addr(cub->screen.img, &cub->screen.bits_per_pixel, &cub->screen.line_len, &cub->screen.endian);
	cub->w_no.img = mlx_xpm_file_to_image(cub->mlx, data->texture.north,
		&cub->w_no.width, &cub->w_no.height);
	if (!cub->w_no.img)
		return_error("Missing texture north");
	cub->w_no.addr = mlx_get_data_addr(cub->w_no.img, &cub->w_no.bits_per_pixel,
		&cub->w_no.line_len, &cub->w_no.endian);
	if (!cub->w_no.addr)
		return_error("Missing texture2");
	cub->w_so.img = mlx_xpm_file_to_image(cub->mlx, data->texture.south,
		&cub->w_so.width, &cub->w_so.height);
	if (!cub->w_so.img)
		return_error("Missing texture south");
	cub->w_so.addr = mlx_get_data_addr(cub->w_so.img, &cub->w_so.bits_per_pixel,
		&cub->w_so.line_len, &cub->w_so.endian);
	if (!cub->w_so.addr)
		return_error("Missing texture4");
	cub->w_ea.img = mlx_xpm_file_to_image(cub->mlx, data->texture.east,
		&cub->w_ea.width, &cub->w_ea.height);
	if (!cub->w_ea.img)
		return_error("Missing texture east");
	cub->w_ea.addr = mlx_get_data_addr(cub->w_ea.img, &cub->w_ea.bits_per_pixel,
		&cub->w_ea.line_len, &cub->w_ea.endian);
	if (!cub->w_ea.addr)
		return_error("Missing texture6");
	cub->w_we.img = mlx_xpm_file_to_image(cub->mlx, data->texture.west,
		&cub->w_we.width, &cub->w_we.height);
	if (!cub->w_we.img)
		return_error("Missing texture west");
	cub->w_we.addr = mlx_get_data_addr(cub->w_we.img, &cub->w_we.bits_per_pixel,
		&cub->w_we.line_len, &cub->w_we.endian);
	if (!cub->w_we.addr)
		return_error("Missing texture8");
	return (1);
}
