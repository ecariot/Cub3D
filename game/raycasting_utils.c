#include "../includes/cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_ceiling(t_cub *cub, t_data *data, int x, int y)
{
	char *dst;

	dst = cub->screen.addr + (y * cub->screen.line_len + x * (cub->screen.bits_per_pixel / 8));
	*(unsigned int *)dst = create_trgb(0, data->texture.ceiling_r,
	data->texture.ceiling_g, data->texture.ceiling_b);
}

void	rotate_right(t_cub *cub)
{
	double	tmp;
	double	tmp_plane;

	tmp = cub->dir.x;
	cub->dir.x = cub->dir.x * cos(0.88) - cub->dir.y * sin(0.88);
	cub->dir.y = tmp * sin(0.88) + cub->dir.y * cos(0.88);
	tmp_plane = cub->plane.x;
	cub->plane.x = cub->plane.x * cos(0.88) - cub->plane.y * sin(0.88);
	cub->plane.y = tmp_plane * sin(0.88) + cub->plane.y * cos(0.88);
}

void	rotate_left(t_cub *cub)
{
	double	tmp;
	double	tmp_plane;

	tmp = cub->dir.x;
	cub->dir.x = cub->dir.x * cos(-0.88) - cub->dir.y * sin(-0.88);
	cub->dir.y = tmp * sin(-0.88) + cub->dir.y * cos(-0.88);
	tmp_plane = cub->plane.x;
	cub->plane.x = cub->plane.x * cos(-0.88) - cub->plane.y * sin(-0.88);
	cub->plane.y = tmp_plane * sin(-0.88) + cub->plane.y * cos(-0.88);
}
