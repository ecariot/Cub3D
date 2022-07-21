#include "../includes/cub.h"

int	ft_errors(char *str)
{
	printf("Error\n%s\n", str);
	return (1);
}

int	put_img(t_data *data)
{
	action_key(&data->cub);
	init_raycasting(&data->cub, data);
	action_key(&data->cub);
	return (1);
}


int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_errors("Wrong nb of args"));
	ft_init_texture(&data);
	ft_init_cub(&data);
	if (ft_check_extension(av[1], ".cub") != 0)
		return (1);
	if (ft_read_map(&data, av[1]) == 1)
		return (1);
	if (ft_parsing(&data, av[1]))
	{
		ft_free_struct(&data);
		return (1);
	}
	init_player(&data.cub);
	if (!(draw_window(&data.cub, &data)))
	{
		return (-1);
	}
	mlx_hook(data.cub.mlx_win, 2, 1L << 0, keycode, &data);
	mlx_hook(data.cub.mlx_win, 17, 0, close_window, &data);
	mlx_loop_hook(data.cub.mlx, put_img, &data);
	mlx_hook(data.cub.mlx_win, 3, 1L << 1, keycode_zero, &data);
	mlx_loop(data.cub.mlx);
	// free_texture(&data.cub);
	// ft_free_tab(data.cub.map);
	return (0);
}

