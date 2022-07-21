/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:18:20 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/21 15:30:00 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == '0' || c == '1'
		|| c == 'W' || c == 'E' || c == '\n' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_start(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int	ft_check_char(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!is_valid_char(map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_if_close(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_is_start(map[y][x]))
			{
				if (y == 0 || x == 0
					|| map[y + 1] == NULL || map[y][x + 1] == '\n')
					return (0);
				if (map[y + 1][x] == ' ' || map[y - 1][x] == ' '
					|| map[y][x + 1] == ' ' || map[y][x - 1] == ' '
					|| map[y + 1][x] == '\0' || map[y][x + 1] == '\0')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_map(t_data *data)
{
	if (!data->cub.map || data->cub.map[0] == NULL)
		return (ft_errors("Empty map"));
	if (!(ft_pick_player(data->cub.map, data)))
		return (ft_errors("Too Many Players"));
	if (!data->cub.player)
		return (ft_errors("No Player"));
	data->cub.map = ft_replace_space_inside(data->cub.map, data);
	if (!data->cub.map)
		return (ft_errors("Map is not closed"));
	if (!(ft_check_char(data->cub.map)))
		return (ft_errors("Wrong char in map"));
	if (!(ft_check_if_close(data->cub.map)))
		return (ft_errors("Map is not closed"));
	return (0);
}
