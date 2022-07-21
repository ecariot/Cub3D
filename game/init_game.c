/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:26:19 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/21 14:45:30 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	draw_window(t_cub *cub, t_data *data)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		exit_error(data, "Erreur");
	mlx_get_screen_size(cub->mlx, &cub->win_width, &cub->win_height);
	cub->mlx_win = mlx_new_window(cub->mlx, cub->win_width, cub->win_height, "Welcome to Saint Tropez");
	cub->screen.img = mlx_new_image(cub->mlx, cub->win_width, cub->win_height);
	cub->screen.addr = mlx_get_data_addr(cub->screen.img, &cub->screen.bits_per_pixel, &cub->screen.line_len, &cub->screen.endian);
	cub->w_no.img = mlx_xpm_file_to_image(cub->mlx, data->texture.north,
		&cub->w_no.width, &cub->w_no.height);
	if (!cub->w_no.img)
		exit_error(data, "Missing texture north");
	cub->w_no.addr = mlx_get_data_addr(cub->w_no.img, &cub->w_no.bits_per_pixel,
		&cub->w_no.line_len, &cub->w_no.endian);
	if (!cub->w_no.addr)
		exit_error(data, "Missing texture2");
	cub->w_so.img = mlx_xpm_file_to_image(cub->mlx, data->texture.south,
		&cub->w_so.width, &cub->w_so.height);
	if (!cub->w_so.img)
	{
		// printf("data map : %s\n", data->cub.map[0]);
		exit_error(data, "Missing texture south");
	}
	cub->w_so.addr = mlx_get_data_addr(cub->w_so.img, &cub->w_so.bits_per_pixel,
		&cub->w_so.line_len, &cub->w_so.endian);
	if (!cub->w_so.addr)
		exit_error(data, "Missing texture4");
	cub->w_ea.img = mlx_xpm_file_to_image(cub->mlx, data->texture.east,
		&cub->w_ea.width, &cub->w_ea.height);
	if (!cub->w_ea.img)
		exit_error(data, "Missing texture east");
	cub->w_ea.addr = mlx_get_data_addr(cub->w_ea.img, &cub->w_ea.bits_per_pixel,
		&cub->w_ea.line_len, &cub->w_ea.endian);
	if (!cub->w_ea.addr)
		exit_error(data, "Missing texture6");
	cub->w_we.img = mlx_xpm_file_to_image(cub->mlx, data->texture.west,
		&cub->w_we.width, &cub->w_we.height);
	if (!cub->w_we.img)
		exit_error(data, "Missing texture west");
	cub->w_we.addr = mlx_get_data_addr(cub->w_we.img, &cub->w_we.bits_per_pixel,
		&cub->w_we.line_len, &cub->w_we.endian);
	if (!cub->w_we.addr)
		exit_error(data, "Missing texture8");
	return (1);
}
