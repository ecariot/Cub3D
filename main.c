/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:51:05 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/04 13:10:08 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_errors(char *str)
{
	printf("Error\n%s\n", str);
	return (0);
}

int main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || ac != 3)
		return (ft_errors("Wrong nb of args"));
	if (check_extension(av[1], &data) != 0)
	{
		close(data.fd);
		return (1);
	}
	ft_parsing(&data);
	return (0);
}
