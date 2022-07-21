/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:12:03 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/21 16:22:21 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	**ft_formatted_color(char **split_line)
{
	char	**split_color;
	int		i;

	if (ft_strlen_tab(split_line) > 2)
	{
		i = 2;
		while (split_line[i])
		{
			split_line[1] = ft_strjoin(split_line[1], split_line[i]);
			i++;
		}
	}
	split_color = ft_split_many(split_line[1], " ,");
	if (!split_color)
	{
		ft_free_tab(split_line);
		return (NULL);
	}
	return (split_color);
}

int	ft_color_is_full(t_texture texture)
{
	if (texture.floor_b >= 0 && texture.floor_r >= 0
		&& texture.floor_r >= 0 && texture.ceiling_r >= 0
		&& texture.ceiling_g >= 0 && texture.ceiling_b >= 0)
		return (1);
	return (0);
}

int	ft_texture_is_full(t_texture texture)
{
	if (texture.north != NULL && texture.south != NULL
		&& texture.west != NULL && texture.east != NULL)
		return (1);
	return (0);
}

char	**ft_replace_space_inside(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->cub.line)
	{
		x = 0;
		while (x <= data->cub.col)
		{
			if (ft_isspace(map[y][x]))
			{
				if (ft_check_buddies(y, x, map, data))
					return (ft_free_tab(map));
				else
					map[y][x] = '1';
			}
			x++;
		}
		y++;
	}
	return (map);
}
