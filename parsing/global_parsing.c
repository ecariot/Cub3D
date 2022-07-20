/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:55:06 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/20 10:59:46 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int ft_parse_elements(t_data *data, char *file)
{
	char **split_line;
	char **split_color;
	char *get_line;
	int i = 0;

	data->cub.map = ft_init_tab(data);
	data->fd = open(file, O_RDONLY, 0);
	if (data->fd == -1)
		return (0);
	get_line = ft_get_next_line(data->fd);
	while (get_line)
	{
		split_line = ft_split_many(get_line, " ");
		if (ft_is_texture(split_line))
		{
			if (is_valid_texture(split_line))
				return (1);
			if (ft_parse_texture(split_line, data))
				return (ft_errors("Texture already exist"));
		}
		else if (ft_is_color(split_line))
		{
			if (ft_strlen_tab(split_line) > 2)
			{
				int i = 2;
				while (split_line[i])
				{
					split_line[1] = ft_strjoin(split_line[1], split_line[i]);
					i++;
				}
			}
			split_color = ft_split_many(split_line[1], " ,");
			if (is_valid_color(split_color))
				return (1);
			if (ft_parse_color(split_line, data))
				return (1);
		}
		else if (ft_is_map(get_line) && get_line[0] != '\n')
		{
			while (i < data->cub.line)
			{
				data->cub.map[i] = ft_replace_space_end(get_line, data);
				if (!data->cub.map[i])
					return (ft_errors("open map"));
				free(get_line);
				get_line = ft_get_next_line(data->fd);
				i++;
			}
			data->cub.map[i] = NULL;
		}
		free(get_line);
		get_line = ft_get_next_line(data->fd);
	}
	close(data->fd);
	return (0);
}


int	ft_parsing(t_data *data, char *file)
{
	int i;

	i = 0;
	if (ft_parse_elements(data, file))
	{
		close(data->fd);
		return (1);
	}
	if (ft_check_map(data))
	{
		return (1);
	}
	if (ft_check_texture(data->texture))
	{
		return (1);
	}
	printf("TEXTURE :\nNorth : %sSouth : %sWest : %sEast : %s", data->texture.north, data->texture.south, data->texture.west, data->texture.east);
	printf("COLOR FLOOR :\nfloor-R : %d\nfloor-G : %d\nfloor-B : %d\n", data->texture.floor_r, data->texture.floor_g, data->texture.floor_b);
	printf("COLOR CEILING :\nceiling-R : %d\nceiling-G : %d\nceiling-B : %d\n", data->texture.ceiling_r, data->texture.ceiling_g, data->texture.ceiling_b);
	printf("MAP :\n");
	int j = 0;
	while (data->cub.map[i])
	{
		j = 0;
		while (data->cub.map[i][j])
		{
			printf("%c", data->cub.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
