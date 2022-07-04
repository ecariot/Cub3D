/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:38:15 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/04 16:50:48 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_parse_color(char **format_color, t_data *data)
{
	printf("Format color : %s\n", format_color[0]);
	printf("Format color : %s\n", format_color[1]);
	printf("Format color : %s\n", format_color[2]);
	printf("Format color : %s\n", format_color[3]);
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
	int j;
	int tmp;

	i = 1;
	j = 0;
	while (format_color[i])
	{
		while (format_color[i][j])
		{
			if (!ft_isdigit(format_color[i][j]))
				return (0);
			j++;
		}
		tmp = ft_atoi(format_color[i]);
		if (tmp > 255 || tmp < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_if_color(char *line, t_data *data)
{
	char **format_color;

	if (!line)
		return (0);
	format_color = ft_split_many(line, " ,");
	if (!format_color || ft_strlen_tab(format_color) != 4)
	{
		ft_free_tab(format_color);
		return (0);
	}
	if (ft_strcmp(format_color[0], "F") || ft_strcmp(format_color[0], "C"))
	{
		ft_free_tab(format_color);
		return (0);
	}
	if (!ft_check_digits(format_color))
	{
		ft_free_tab(format_color);
		return (2);
	}
	ft_parse_color(format_color, data);
	return (1);
}

void	ft_parse_texture(char **format_texture, t_data *data)
{
	if (!ft_strcmp(format_texture[0], "SO"))
		data->texture.south = ft_strdup(format_texture[1]);
	else if (!ft_strcmp(format_texture[0], "NO"))
		data->texture.north = ft_strdup(format_texture[1]);
	else if (!ft_strcmp(format_texture[0], "WE"))
		data->texture.west = ft_strdup(format_texture[1]);
	else if (!ft_strcmp(format_texture[0], "EA"))
		data->texture.east = ft_strdup(format_texture[1]);
	ft_free_tab(format_texture);
}

int	ft_check_if_texture(char *line, t_data *data)
{
	char **format_texture;

	if (!line)
		return (0);
	format_texture = ft_split(line, ' ');
	if (!format_texture || format_texture[2] != NULL || format_texture[1] == NULL)
	{
		ft_free_tab(format_texture);
		return (0);
	}
	else if (!ft_strcmp(format_texture[0], "SO") && !ft_strcmp(format_texture[0], "NO") &&
		!ft_strcmp(format_texture[0], "WE") && !ft_strcmp(format_texture[0], "EA"))
	{
		ft_free_tab(format_texture);
		return (0);
	}
	// if (ft_check_extension(format_texture[1], ".xpm"))
	// {
	// 	ft_free_tab(format_texture);
	// 	return (2);
	// }
	ft_parse_texture(format_texture, data);
	return (1);
}
