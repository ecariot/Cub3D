/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:00:07 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 15:36:32 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	floor_pixel_put(t_data *data, t_cub *cub, int x, int y)
{
	char	*dst;

	dst = cub->screen.addr + cub->screen.line_len * y
		+ x * cub->screen.bits_per_pixel / 8;
	*(unsigned int *)dst = create_trgb(0, data->texture.floor_r,
			data->texture.floor_g, data->texture.floor_b);
}

void	draw_ceiling(t_cub *cub, t_data *data, int x, int y)
{
	char	*dst;

	dst = cub->screen.addr + (y * cub->screen.line_len + x
			* (cub->screen.bits_per_pixel / 8));
	*(unsigned int *)dst = create_trgb(0, data->texture.ceiling_r,
			data->texture.ceiling_g, data->texture.ceiling_b);
}

void	rotate_right(t_cub *cub)
{
	double	tmp;
	double	tmp_plane;
	double	rot_speed;

	rot_speed = (20.0 / 1000.0) * 3.0;
	tmp = cub->dir.x;
	cub->dir.x = cub->dir.x * cos(rot_speed) - cub->dir.y * sin(rot_speed);
	cub->dir.y = tmp * sin(rot_speed) + cub->dir.y * cos(rot_speed);
	tmp_plane = cub->plane.x;
	cub->plane.x = cub->plane.x * cos(rot_speed)
		- cub->plane.y * sin(rot_speed);
	cub->plane.y = tmp_plane * sin(rot_speed) + cub->plane.y * cos(rot_speed);
}
