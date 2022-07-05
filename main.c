/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:53:06 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/05 13:44:49 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_errors(char *str)
{
	printf("Error\n%s\n", str);
	return (1);
}

int main(int ac, char **av)
{
	t_data	data;
	t_cub cub;

	if (ac != 2)
		return (ft_errors("Wrong nb of args"));
	data.fd = open(av[1], O_RDONLY);
	init_struct(&cub);
	if (ft_check_extension(av[1], ".cub") != 0)
	{
		close(data.fd);
		return (1);
	}
	// draw_window(&cub);
	mlx_hook(cub.mlx_win, 17, 1L << 2, close_window, &cub);
	mlx_hook(cub.mlx_win, 2, 1L << 0, keycode, &cub);
	mlx_loop(cub.mlx);
	ft_parsing(&data);

	return (0);
}
