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
