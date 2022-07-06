/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:38:15 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/06 15:08:39 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_parse_color(char **split_line, t_data *data)
{
	if (!ft_strcmp(split_line[0], "F") && !ft_color_is_full(data->texture))
	{
		data->texture.floor_r = ft_atoi(split_line[1]);
		data->texture.floor_g = ft_atoi(split_line[2]);
		data->texture.floor_b = ft_atoi(split_line[3]);
	}
	else if (!ft_strcmp(split_line[0], "C") && !ft_color_is_full(data->texture))
	{
		data->texture.ceiling_r = ft_atoi(split_line[1]);
		data->texture.ceiling_g = ft_atoi(split_line[2]);
		data->texture.ceiling_b = ft_atoi(split_line[3]);
	}
	else
	{
		ft_free_tab(split_line);
		return (1);
	}
	ft_free_tab(split_line);
	return(0);
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
		return (1);
	}
	ft_free_tab(split_line);
	return (0);
}

int ft_is_color(char **split_line)
{
	if (!ft_strncmp(split_line[0], "F", 2) || !ft_strncmp(split_line[0], "C", 2))
		return (1);
	else
		return (0);
}

int ft_is_texture(char **split_line)
{
	if (!ft_strncmp(split_line[0], "SO", 2) || !ft_strncmp(split_line[0], "NO", 2) ||
			!ft_strncmp(split_line[0], "WE", 2) || !ft_strncmp(split_line[0], "EA", 2))
				return (1);
	else
		return (0);
}
