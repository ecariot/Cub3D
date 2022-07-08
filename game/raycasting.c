#include "../includes/cub.h"

void init_step_and_side(t_cub *cub)
{
	if (cub->raydir.x < 0)
	{
		cub->step.x = -1;
		cub->sidedist.x = (cub->pos.x - cub->tab.x) * cub->deltadist.x;
	}
	else
	{
		cub->step.x = 1;
		cub->sidedist.x = (cub->tab.x + 1.0 - cub->pos.x) * cub->deltadist.x;
	}
	if (cub->raydir.y < 0)
	{
		cub->step.y = -1;
		cub->sidedist.y = (cub->pos.y - cub->tab.y) * cub->deltadist.y;
	}
	else
	{
		cub->step.y = 1;
		cub->sidedist.y = (cub->tab.y + 1.0 - cub->pos.y) * cub->deltadist.y;
	}
}

int	perform_dda(t_cub *cub)
{
	int	side;

	side = 0;
	//si le side est 0 cest qu'on voit soit le sud soit le north
	//si side est 1 on voit soit l'east soit west;
	while (cub->hit == 0)
	{
		// printf("SIDE DIST.X = ");
		// scanf("%lf", &cub->sidedist.x);
		if (cub->sidedist.x < cub->sidedist.y)
		{
			printf("PLAYER VOIT LE  NORTH\n");
			cub->sidedist.x += cub->deltadist.x;
			cub->tab.x += cub->step.x;
			side = 0;
			if (cub->raydir.x < 0)
			{
				cub->side_wall = SOUTH;
			}
			else
			{
				cub->side_wall = NORTH;
			}
		}
		else
		{
			cub->sidedist.y += cub->deltadist.y;
			cub->tab.y += cub->step.y;
			side = 1;
			if (cub->raydir.y < 0)
				cub->side_wall = WEST;
			else
				cub->side_wall = EAST;
		}
		if (cub->map[(int)cub->tab.x][(int)cub->tab.y] > 0)
			cub->hit = 1;
	}
	return (side);
}

// int wall_pixel_put(t_cub *cub)
// {
// 	//savoir quel mur afficher  ?
// 	// je pense qu'il faut recuperer la face a afficher dans perform_dda
// 		// => return mur et pas side

// }

void	calcul_ray_pos_and_dir(t_cub *cub, int x)
{
	//init variable de raycasting
	cub->camerax = 2 * x / (double)cub->col - 1;
	cub->raydir.x = cub->dir.x + cub->plane.x * cub->camerax;
	cub->raydir.y = cub->dir.y + cub->plane.y * cub->camerax;
	cub->tab.x = cub->pos.x;
	cub->tab.y = cub->pos.y;
	if (cub->raydir.x == 0)
		cub->deltadist.x = 1e32;
	else
		cub->deltadist.x = fabs(1 / cub->raydir.x);
	if (cub->raydir.y == 0)
		cub->deltadist.y = 1e32;
	else
		cub->deltadist.y = fabs(1 / cub->raydir.y);
	// cub->deltadist.x = fabs(1 / cub->raydir.x);
	// cub->deltadist.y = fabs(1 / cub->raydir.y);
	//calculate step and side

}

int init_raycasting(t_cub *cub)
{
	int x;
	// int i;
	int side;
	double perpWallDist;

	x = 0;
	side = 0;
	// i = 0;
	while (x < cub->col)
	{
		init_step_and_side(cub);
		calcul_ray_pos_and_dir(cub, x);
		//algo dda
		perform_dda(cub);
		//calculate distance of perpendicular ray and
		//calculate value of dur mur qui a ete hit
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
		//calcule la hauteur du nmur a dessier
		cub->wall_len = (double)cub->win_height / perpWallDist;
		// printf("WALL SIDE = %d\n", cub->side_wall);
		//tant que i n'a pas atteint le pixel de fin a dessiner bah tu dessines -> coder wall_pixel
		// while (i < (cub->win_height / 2 + cub->wall_len / 2))
		//{
			// 	wall_pixel_put(cub);
				// i++;
		//}
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen.img, 0, 0);
	return (0);
}



