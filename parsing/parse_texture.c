/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:38:15 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/06 15:20:12 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_parse_color(char **format_color, t_data *data)
{
	if (!ft_strcmp(format_color[0], "F"))
	{
		data->texture.floor_r = ft_atoi(format_color[1]);
		data->texture.floor_g = ft_atoi(format_color[2]);
		data->texture.floor_b = ft_atoi(format_color[3]);
	}
	else if (!ft_strcmp(format_color[0], "C"))
	{
		data->texture.ceiling_r = ft_atoi(format_color[1]);
		data->texture.ceiling_g = ft_atoi(format_color[2]);
		data->texture.ceiling_b = ft_atoi(format_color[3]);
	}
	ft_free_tab(format_color);
}

int ft_check_digits(char **format_color)
{
	int i;
	int tmp;

	i = 1;
	while (format_color[i])
	{
		tmp = ft_atoi(format_color[i]);
		if (tmp > 255 || tmp < 0 || !tmp)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_if_color(char **line, t_data *data)
{
	// char **format_color;

	// if (!line)
	// 	return (0);
	// format_color = ft_split_many(line, " ,");
	// if (ft_strncmp(format_color[0], "F", 2) && ft_strncmp(format_color[0], "C", 2))
	// {
	// 	ft_free_tab(format_color);
	// 	return (0);
	// }
	if (!line || ft_strlen_tab(line) != 4)
	{
		ft_free_tab(line);
		return (0);
	}
	if (!ft_check_digits(line))
	{
		ft_free_tab(line);
		return (0);
	}
	ft_parse_color(line, data);
	return (1);
}

int	ft_parse_texture(char **split_line, t_data *data)
{
	if (!ft_strcmp(split_line[0], "SO") && data->texture.south == NULL)
		data->texture.south = ft_strdup(split_line[1]);
	else if (!ft_strcmp(split_line[0], "NO") && data->texture.north == NULL)
		data->texture.north = ft_strdup(split_line[1]);
	else if (!ft_strcmp(split_line[0], "WE") && data->texture.west == NULL)
		data->texture.west = ft_strdup(split_line[1]);
	else if (!ft_strcmp(split_line[0], "EA") && data->texture.east == NULL)
		data->texture.east = ft_strdup(split_line[1]);
	else
	{
		ft_free_tab(split_line);
		return (0);
	}
	ft_free_tab(split_line);
	return (1);
}

int ft_is_texture(char **split_line)
{
	if (split_line[0][0] == '\n')
		return (0);
	if (!ft_strncmp(split_line[0], "SO", 2) || !ft_strncmp(split_line[0], "NO", 2) ||
			!ft_strncmp(split_line[0], "WE", 2) || !ft_strncmp(split_line[0], "EA", 2))
			{
				return (1);
			}
	else
		return (0);
}

int	ft_check_if_texture(char **line, t_data *data)
{
	// char **format_texture;

	// if (!line)
	// 	return (0);
	// format_texture = ft_split(line, ' ');
	// if (!ft_strcmp(format_texture[0], "SO") && !ft_strcmp(format_texture[0], "NO") &&
	// 	!ft_strcmp(format_texture[0], "WE") && !ft_strcmp(format_texture[0], "EA"))
	// {
	// 	ft_free_tab(format_texture);
	// 	return (0);
	// }
	(void)data;
	if (!line || line[2] != NULL || line[1] == NULL)
	{
		ft_free_tab(line);
		return (0);
	}
	// if (ft_check_extension(format_texture[1], ".xpm"))
	// {
	// 	ft_free_tab(format_texture);
	// 	return (2);
	// }
	// ft_parse_texture(line, data);
	return (1);
}
