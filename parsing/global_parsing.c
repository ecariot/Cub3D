/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:00:42 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/21 16:12:27 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	work_on_color(char **split_line, t_data *data)
{
	char	**split_color;

	split_color = ft_formatted_color(split_line);
	if (!is_valid_color(split_color))
		ft_parse_color(split_line, split_color, data);
	ft_free_tab(split_color);
}

void	work_on_texture(char **split_line, t_data *data)
{
	if (!is_valid_texture(split_line))
		ft_parse_texture(split_line, data);
}

char	*work_on_map(char *get_line, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cub.line)
	{
		data->cub.map[i] = ft_replace_space_end(get_line, data);
		free(get_line);
		get_line = ft_get_next_line(data->fd);
		i++;
	}
	data->cub.map[i] = NULL;
	return (get_line);
}

int	ft_parse_elements(t_data *data, char *file)
{
	char	**split_line;
	char	*get_line;

	data->fd = open(file, O_RDONLY, 0);
	if (data->fd == -1)
		return (1);
	get_line = ft_get_next_line(data->fd);
	data->cub.map = ft_init_tab(data);
	while (get_line)
	{
		split_line = ft_split_many(get_line, " ");
		if (ft_is_texture(split_line))
			work_on_texture(split_line, data);
		else if (ft_is_color(split_line))
			work_on_color(split_line, data);
		else if (ft_is_map(get_line) && get_line[0] != '\n')
			get_line = work_on_map(get_line, data);
		free(get_line);
		ft_free_tab(split_line);
		get_line = ft_get_next_line(data->fd);
	}
	close(data->fd);
	return (0);
}

int	ft_parsing(t_data *data, char *file)
{
	if (ft_parse_elements(data, file))
	{
		close(data->fd);
		return (1);
	}
	if (ft_check_texture(data->texture))
	{
		if (data->cub.map)
			ft_free_tab(data->cub.map);
		return (1);
	}
	if (ft_check_map(data))
	{
		if (data->cub.map)
			ft_free_tab(data->cub.map);
		return (1);
	}
	return (0);
}
