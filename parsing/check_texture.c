/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:56:21 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/19 17:55:38 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int ft_check_digits(char **format_color)
{
	int i;
	int tmp;

	i = 1;
	while (format_color[i])
	{
		tmp = ft_atoi(format_color[i]);
		if (tmp > 255 || tmp < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_color_is_full(t_texture texture)
{
	if (texture.floor_b >= 0 && texture.floor_r >= 0 &&
		texture.floor_r >= 0 && texture.ceiling_r >= 0 &&
		texture.ceiling_g >= 0 && texture.ceiling_b >= 0)
			return (1);
	return (0);
}

int	ft_texture_is_full(t_texture texture)
{
	if (texture.north != NULL && texture.south != NULL &&
		texture.west != NULL && texture.east != NULL)
			return (1);
	return (0);
}

int	ft_check_texture(t_texture texture)
{
	if (!ft_texture_is_full(texture))
		return (ft_errors("Texture is missing"));
	if (!ft_color_is_full(texture))
		return (ft_errors("Color is missing"));
	return (0);
}

int	is_valid_texture(char **split_line)
{
	if (split_line[1] == NULL || !split_line)
		return (ft_errors("Texture is missing"));
	if (split_line[2] != NULL)
		return (ft_errors("Too much texture"));
	return (0);
}

int	is_valid_digit(char **split_line)
{
	int i = 1;
	int j;

	while (split_line[i])
	{
		j = 0;
		// printf("split_line = %s\n", split_line[i]);
		while (split_line[i][j])
		{
			if (!ft_isdigit(split_line[i][j]) && split_line[i][j] != '\n')
			{
				// printf("char = %c\n", split_line[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_color(char **split_line)
{
	if (is_valid_digit(split_line) == 1)
		return (ft_errors("Wrong char in colors"));
	if (ft_strlen_tab(split_line) < 4)
		return (ft_errors("Color is missing"));
	if (ft_strlen_tab(split_line) > 4)
		return (ft_errors("Too Much color"));
	else if (!ft_check_digits(split_line))
		return (ft_errors("Color must be between 0 and 255"));
	return (0);
}

