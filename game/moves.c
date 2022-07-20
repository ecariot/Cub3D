#include "../includes/cub.h"

void	move_down(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;

	posy = floor(cub->pos.y + cub->dir.y * moveSpeed);
	posx = floor(cub->pos.x + cub->dir.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->dir.y * moveSpeed);
	cub->pos.x += (cub->dir.x * moveSpeed);
}

void	move_forward(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;

	posy = floor(cub->pos.y - cub->dir.y * moveSpeed);
	posx = floor(cub->pos.x - cub->dir.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->dir.y * moveSpeed);
	cub->pos.x -= (cub->dir.x * moveSpeed);
}

void	move_left(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;

	posy = floor(cub->pos.y - cub->plane.y * moveSpeed);
	posx = floor(cub->pos.x - cub->plane.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y -= (cub->plane.y * moveSpeed);
	cub->pos.x -= (cub->plane.x * moveSpeed);
}

void	move_right(t_cub *cub)
{
	int posy;
	int posx;
	double moveSpeed = 0.1;


	posy = floor(cub->pos.y + cub->plane.y * moveSpeed);
	posx = floor(cub->pos.x + cub->plane.x * moveSpeed);
	if (cub->map[posy][posx] == '1')
		return ;
	cub->pos.y += (cub->plane.y * moveSpeed);
	cub->pos.x += (cub->plane.x * moveSpeed);
}

void	action_key(t_cub *cub)
{
	if (cub->right == 1)
		move_right(cub);
	if (cub->left == 1)
		move_left(cub);
	if (cub->forward == 1)
		move_forward(cub);
	if (cub->down == 1)
		move_down(cub);
	if (cub->rotate_r)
		rotate_right(cub);
	if (cub->rotate_l)
		rotate_left(cub);
}

int	keycode(int key, t_cub *cub)
{
	if (key == ESC)
		close_window(cub);
	if (key == D)
		cub->right = 1;
	if (key == A)
		cub->left = 1;
	if (key == S)
		cub->forward = 1;
	if (key == W)
		cub->down = 1;
	if (key == RIGHT)
		cub->rotate_r = 1;
	if (key == LEFT)
		cub->rotate_l = 1;
	return (1);
}

int	keycode_zero(int key, t_cub *cub)
{
	if (key == D)
		cub->right = 0;
	if (key == A)
		cub->left = 0;
	if (key == S)
		cub->forward = 0;
	if (key == W)
		cub->down = 0;
	if (key == RIGHT)
		cub->rotate_r = 0;
	if (key == LEFT)
		cub->rotate_l = 0;
	if (key == ESC)
		close_window(cub);
	return (1);
}
