/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:35:57 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/06 16:31:59 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int is_valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == '0' || c == '1'
		|| c == 'W' || c == 'E' || c == '\n')
		return (1);
	else
		return (0);
}

int ft_is_start(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}



int ft_check_char(char **map)
{
	int x;
	int y;

	x = 0;
	while(map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!is_valid_char(map[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_check_if_close(char **map)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_is_start(map[x][y]))
			{
				// check les bords
				if (x == 0 || y == 0 || map[x + 1] == NULL || map[x][y + 1] == '\n')
					return (0);
				// check tes potes a l'interieur
				if (map[x + 1][y] == ' '|| map[x - 1][y] == ' ' ||
					map[x][y + 1] == ' ' || map[x][y - 1] == ' ' ||
					map[x + 1][y] == '\0' || map[x][y + 1] == '\0')
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_check_player(char **map, t_cub *cub)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_is_start(map[x][y]) && map[x][y] != '0')
			{
				if (cub->player == 0)
					cub->player = 1;
				else
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_check_map(t_cub cub)
{
	if (!(ft_check_char(cub.map)))
		return (ft_errors("Wrong char in map"));
	if (!(ft_check_if_close(cub.map)))
		return (ft_errors("Map is not closed"));
	if (!(ft_check_player(cub.map, &cub)))
		return (ft_errors("Too Many Players"));
	return (1);
}


