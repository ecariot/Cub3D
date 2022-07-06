/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:51:05 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/06 13:58:09 by mbascuna         ###   ########.fr       */
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

	if (ac != 2)
		return (ft_errors("Wrong nb of args"));
	ft_init_texture(&data);
	ft_init_cub(&data);
	if (ft_check_extension(av[1], ".cub") != 0)
	{
		close(data.fd);
		return (1);
	}
	ft_read_map(&data, av[1]);
	// data.fd = open(av[1], O_RDONLY);
	ft_parsing(&data, av[1]);
	return (0);
}
