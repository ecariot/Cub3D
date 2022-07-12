#include "../includes/cub.h"

void init_step_and_side(t_cub *cub)
{
	if (cub->raydir.x < 0.)
	{
		cub->step.x = -1.;
		cub->sidedist.x = (cub->pos.x - cub->tab.x) * cub->deltadist.x;
	}
	else
	{
		cub->step.x = 1.;
		cub->sidedist.x = (cub->tab.x + 1.0 - cub->pos.x) * cub->deltadist.x;
	}
	if (cub->raydir.y < 0.)
	{
		cub->step.y = -1.;
		cub->sidedist.y = (cub->pos.y - cub->tab.y) * cub->deltadist.y;
	}
	else
	{
		cub->step.y = 1.;
		cub->sidedist.y = (cub->tab.y + 1.0 - cub->pos.y) * cub->deltadist.y;
	}
	// printf("POS.X = %lf\n", cub->pos.x);
	// printf("SIDE.X = %lf\n", cub->sidedist.x);
	// printf("DELTA.X = %lf\n", cub->deltadist.x);
	// printf("RAYDIR.X = %lf\n", cub->raydir.x);
	// printf("RAYDIR.Y = %lf\n", cub->raydir.y);
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
			if (cub->raydir.x < 0.)
				cub->side_wall = NORTH;
			else
				cub->side_wall = SOUTH;
		}
		else
		{
			cub->sidedist.y += cub->deltadist.y;
			cub->tab.y += cub->step.y;
			side = 1;
			if (cub->raydir.y < 0.)
				cub->side_wall = EAST;
			else
				cub->side_wall = WEST;
		}
		if (cub->map[(int)cub->tab.x][(int)cub->tab.y] == '1')
		{
			cub->hit = 1;
			// printf("side = %d\n", side);
			// printf("MAP = %c\n", cub->map[(int)cub->tab.x][(int)cub->tab.y]);
		}
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
	px = (y * cub->screen.line_len + x * cub->screen.bits_per_pixel / 8);
	y = y - (cub->win_height / 2 - cub->wall_len / 2);
	x2 = (int)(cub->wallx * (double)print_wall->width);
	if (cub->side_wall == WEST || cub->side_wall == NORTH)
		x2 = print_wall->width - x2 - 1;
	y2 = (int)((double)y * (double)print_wall->height / cub->wall_len);
	px2 = print_wall->line_len * y2 + x2 * print_wall->bits_per_pixel / 8;
	cub->screen.addr[px] = (char)print_wall->addr[px2];
	cub->screen.addr[px + 1] = (char)print_wall->addr[px2 + 1];
	// printf("PLAYER VOIT LE NORTH\n");
	cub->screen.addr[px + 2] = (char)print_wall->addr[px2 + 2];
}

void	calcul_ray_pos_and_dir(t_cub *cub, int x)
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
}

int init_raycasting(t_cub *cub)
{
	int x;
	int y;
	int side;
	double perpWallDist;

	x = 0;
	side = 0;
	y = 0;
	init_player(cub);
	while (x < cub->win_width)
	{
		calcul_ray_pos_and_dir(cub, x);
		init_step_and_side(cub);
		side = perform_dda(cub);
		if (!side)
			perpWallDist = (cub->sidedist.x - cub->deltadist.x);
		else
			perpWallDist = (cub->sidedist.y - cub->deltadist.y);
		if (!side)
			cub->wallx = cub->pos.y + perpWallDist * cub->raydir.y;
		else
			cub->wallx = cub->pos.x + perpWallDist * cub->raydir.x;
		cub->wallx -= floor((cub->wallx));
		if (perpWallDist < 1.)
			perpWallDist = 1;
		cub->wall_len = (double)cub->win_height / perpWallDist;
		y = 0;
		while (y < (cub->win_height / 2 + cub->wall_len / 2))
		{
			wall_pixel_put(cub, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen.img, 0, 0);
	return (0);
}



