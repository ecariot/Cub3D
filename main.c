#include "../includes/cub.h"

int	ft_errors(char *str)
{
	printf("Error\n%s\n", str);
	return (1);
}

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_errors("Wrong nb of args"));
	ft_init_texture(&data);
	ft_init_cub(&data);
	data.fd = open(av[1], O_RDONLY);
	if (ft_check_extension(av[1], ".cub") != 0)
	{
		close(data.fd);
		return (1);
	}
	ft_read_map(&data, av[1]);
	// data.fd = open(av[1], O_RDONLY);
	ft_parsing(&data, av[1]);
	if (!(draw_window(&data.cub, &data)))
	{
		//free
		return (-1);
	}
	mlx_hook(data.cub.mlx_win, 17, 1L << 2, close_window, &data.cub);
	mlx_hook(data.cub.mlx_win, 2, 1L << 0, keycode, &data.cub);
	mlx_loop_hook(data.cub.mlx, put_img, &data.cub);
	mlx_loop(data.cub.mlx);
	return (0);
}
