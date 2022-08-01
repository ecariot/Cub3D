/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:32:14 by mbascuna          #+#    #+#             */
/*   Updated: 2022/08/01 11:50:14 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	exit_error(t_data *data, char *str)
{
	printf("Error\n%s\n", str);
	ft_free_struct(data);
	ft_free_tab(data->cub.map);
	free_texture(&data->cub);
	if (data->cub.mlx_win)
		mlx_destroy_window(data->cub.mlx, data->cub.mlx_win);
	if (data->cub.mlx)
	{
		mlx_destroy_display(data->cub.mlx);
		free(data->cub.mlx);
	}
	close(data->fd);
	exit (0);
}

int	exit_mlx(t_data *data, char *str)
{
	printf("Error\n%s\n", str);
	ft_free_struct(data);
	ft_free_tab(data->cub.map);
	free_texture(&data->cub);
	close(data->fd);
	exit (0);
}

int	free_texture(t_cub *cub)
{
	if (cub->w_no.img)
		mlx_destroy_image(cub->mlx, cub->w_no.img);
	if (cub->w_so.img)
		mlx_destroy_image(cub->mlx, cub->w_so.img);
	if (cub->w_ea.img)
		mlx_destroy_image(cub->mlx, cub->w_ea.img);
	if (cub->w_we.img)
		mlx_destroy_image(cub->mlx, cub->w_we.img);
	if (cub->screen.img)
		mlx_destroy_image(cub->mlx, cub->screen.img);
	return (1);
}
