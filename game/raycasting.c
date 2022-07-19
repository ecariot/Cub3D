#include "../includes/cub.h"

void init_step_and_side(t_cub *cub)
{
	if (cub->raydir.x < 0.)
	{
		cub->step.x = -1.0;
		cub->sidedist.x = (cub->pos.x - cub->tab.x) * cub->deltadist.x;
	}
	else
	{
		cub->step.x = 1.0;
		cub->sidedist.x = (cub->tab.x + 1.0 - cub->pos.x) * cub->deltadist.x;
	}
	if (cub->raydir.y < 0.)
	{
		cub->step.y = -1.0;
		cub->sidedist.y = (cub->pos.y - cub->tab.y) * cub->deltadist.y;
	}
	else
	{
		cub->step.y = 1.0;
		cub->sidedist.y = (cub->tab.y + 1.0 - cub->pos.y) * cub->deltadist.y;
	}
}

int	perform_dda(t_cub *cub)
{
	int	side;

	side = 0;
	while (cub->hit == 0)
	{
		if (cub->sidedist.x < cub->sidedist.y)
		{
			cub->sidedist.x += cub->deltadist.x;
			cub->tab.x += cub->step.x;
			side = 0;
			if (cub->raydir.x < 0.0)
				cub->side_wall = NORTH;
			else
				cub->side_wall = SOUTH;
		}
		else
		{
			cub->sidedist.y += cub->deltadist.y;
			cub->tab.y += cub->step.y;
			side = 1;
			if (cub->raydir.y < 0.0)
				cub->side_wall = EAST;
			else
				cub->side_wall = WEST;
		}
		if (cub->map[(int)cub->tab.y][(int)cub->tab.x] == '1')
			cub->hit = 1;
	}
	return (side);
}

t_pic *recup_wall(t_cub *cub)
{
	if (cub->side_wall == NORTH)
		return (&cub->w_no);
	if (cub->side_wall == SOUTH)
		return (&cub->w_so);
	if (cub->side_wall == EAST)
		return (&cub->w_ea);
	if (cub->side_wall == WEST)
		return (&cub->w_we);
	return (&cub->w_no);
}

void wall_pixel_put(t_cub *cub, int x, int y)
{
	int	px;
	int	px2;
	int	x2;
	int	y2;
	t_pic *print_wall;

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

void    floor_pixel_put(t_data *data, t_cub *cub, int x, int y)
{
    char    *dst;

    dst = cub->screen.addr + cub->screen.line_len * y + x * cub->screen.bits_per_pixel / 8;
    *(unsigned int*)dst = create_trgb(0, data->texture.floor_r, data->texture.floor_g, data->texture.floor_b);
}

int init_raycasting(t_cub *cub, t_data *data)
{
	int x;
	int y;
	int side;
	double perpWallDist;
	int draw_end;

	x = 0;
	side = 0;
	while (x < cub->win_width)
	{
		//init variable de raycasting
		cub->camerax = 2.0 * x / (double)cub->win_width - 1.0;
		cub->raydir.x = cub->dir.x + cub->plane.x * cub->camerax;
		cub->raydir.y = cub->dir.y + cub->plane.y * cub->camerax;
		cub->tab.x = (int)cub->pos.x;
		cub->tab.y = (int)cub->pos.y;
		cub->hit = 0;
		cub->deltadist.x = fabs(1.0 / cub->raydir.x);
		cub->deltadist.y = fabs(1.0 / cub->raydir.y);
		init_step_and_side(cub);
		side = perform_dda(cub);
		if (!side)
		{
			perpWallDist = (cub->sidedist.x - cub->deltadist.x);
			cub->wallx = cub->pos.y + perpWallDist * cub->raydir.y;
		}
		else
		{
			perpWallDist = (cub->sidedist.y - cub->deltadist.y);
			cub->wallx = cub->pos.x + perpWallDist * cub->raydir.x;
		}
		cub->wallx -= floor((cub->wallx));
		if (perpWallDist < 1.0)
			perpWallDist = 1;
		cub->wall_len = (double)cub->win_height / perpWallDist;
		y = 0;
		while (y < (-cub->wall_len / 2 + cub->win_height / 2))
		{
			draw_ceiling(cub, data, x, y);
			y++;
		}
		y = -cub->wall_len / 2 + cub->win_height / 2;
		if (y < 0)
			y = 0;
		draw_end = cub->win_height / 2 + cub->wall_len / 2;
		if (draw_end >= cub->win_height)
			draw_end = cub->win_height;
		while (y < draw_end)
		{
			wall_pixel_put(cub, x, y);
			y++;
		}
		while (y < (cub->win_height))
		{
			floor_pixel_put(data, cub, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen.img, 0, 0);
	return (0);
}



