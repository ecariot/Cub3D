/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:05:25 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 15:20:30 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	wall_pixel_put(t_cub *cub, int x, int y)
{
	int		px;
	int		px2;
	int		x2;
	int		y2;
	t_pic	*print_wall;

	print_wall = recup_wall(cub);
	px = cub->screen.line_len * y + x * cub->screen.bits_per_pixel / 8;
	y = y - (cub->win_height / 2 - cub->wall_len / 2);
	x2 = (int)(cub->wallx * (double)print_wall->width);
	if (cub->side_wall == WEST || cub->side_wall == NORTH)
		x2 = print_wall->width - x2 - 1;
	y2 = (int)((double)y * (double)print_wall->height / cub->wall_len);
	px2 = print_wall->line_len * y2 + x2 * print_wall->bits_per_pixel / 8;
	cub->screen.addr[px + 2] = (char)print_wall->addr[px2 + 2];
	cub->screen.addr[px + 1] = (char)print_wall->addr[px2 + 1];
	cub->screen.addr[px] = (char)print_wall->addr[px2];
}

void	init_camerax(t_cub *cub, int x)
{
	cub->camerax = 2.0 * x / (double)cub->win_width - 1.0;
	cub->raydir.x = cub->dir.x + cub->plane.x * cub->camerax;
	cub->raydir.y = cub->dir.y + cub->plane.y * cub->camerax;
	cub->tab.x = (int)cub->pos.x;
	cub->tab.y = (int)cub->pos.y;
	cub->hit = 0;
	cub->deltadist.x = fabs(1.0 / cub->raydir.x);
	cub->deltadist.y = fabs(1.0 / cub->raydir.y);
}

double	side_search(t_cub *cub, int x)
{
	int		side ;
	double	perp_wall_dist;

	side = 0;
	perp_wall_dist = 0;
	init_camerax(cub, x);
	init_step_and_side(cub);
	side = perform_dda(cub);
	if (!side)
	{
		perp_wall_dist = (cub->sidedist.x - cub->deltadist.x);
		cub->wallx = cub->pos.y + perp_wall_dist * cub->raydir.y;
	}
	else
	{
		perp_wall_dist = (cub->sidedist.y - cub->deltadist.y);
		cub->wallx = cub->pos.x + perp_wall_dist * cub->raydir.x;
	}
	return (perp_wall_dist);
}

void	draw_game(t_data *data, t_cub *cub, int x, int y)
{
	int	draw_end;

	while (y < (-cub->wall_len / 2 + cub->win_height / 2))
		draw_ceiling(cub, data, x, y++);
	y = -cub->wall_len / 2 + cub->win_height / 2;
	if (y < 0)
		y = 0;
	draw_end = cub->win_height / 2 + cub->wall_len / 2;
	if (draw_end >= cub->win_height)
		draw_end = cub->win_height;
	while (y < draw_end)
		wall_pixel_put(cub, x, y++);
	while (y < (cub->win_height))
		floor_pixel_put(data, cub, x, y++);
}

int	init_raycasting(t_cub *cub, t_data *data)
{
	int		x;
	int		y;
	double	perp_wall_dist;

	x = 0;
	while (x < cub->win_width)
	{
		perp_wall_dist = side_search(cub, x);
		cub->wallx -= floor((cub->wallx));
		if (perp_wall_dist < 1.0)
			perp_wall_dist = 1;
		cub->wall_len = (double)cub->win_height / perp_wall_dist;
		y = 0;
		draw_game(data, cub, x, y);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen.img, 0, 0);
	return (0);
}
