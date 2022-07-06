/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:31:20 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/06 14:43:29 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void ft_init_texture(t_data *data)
{
	data->texture.floor_r = -1;
	data->texture.floor_g = -1;
	data->texture.floor_b = -1;
	data->texture.ceiling_r = -1;
	data->texture.ceiling_g = -1;
	data->texture.ceiling_b = -1;
	data->texture.north = NULL;
	data->texture.south = NULL;
	data->texture.east = NULL;
	data->texture.west = NULL;
}

void ft_init_cub(t_data *data)
{
	data->cub.line = 0;
	data->cub.col = 0;
	data->cub.width = 0;
	data->cub.dirY = 0;
	data->cub.dirX = 0;
	data->cub.posY = 0;
	data->cub.posX = 0;
	data->cub.map = NULL;
}

void	ft_read_map(t_data *data, char *file)
{
	char	*get_line;
	int		fd;

	fd = open(file, O_RDONLY);
	get_line = ft_get_next_line(fd);
	if (!get_line)
		ft_errors("Error : file");
	data->cub.col = ft_strlen(get_line);
	data->cub.line = 0;
	while (get_line)
	{
		free(get_line);
		get_line = ft_get_next_line(fd);
		if (ft_is_map(get_line))
			data->cub.line++;
		if (ft_strlen(get_line) > (size_t)data->cub.col)
			data->cub.col = ft_strlen(get_line);
	}
	close(fd);
}

char	**ft_init_tab(t_data *data)
{
	char **tab;
	int tmp;

	tmp = data->cub.line;
	tab = (char **)malloc(sizeof(char *) * (data->cub.line + 1));
	if (!tab)
		return (NULL);
	tab[data->cub.line] = NULL;
	while (tmp > 0)
	{
		tmp--;
		tab[tmp] = (char *)malloc(sizeof(char) * (data->cub.col));
		if (!tab[tmp])
		{
			ft_free_tab(tab);
			return (NULL);
		}
	}
	return (tab);
}
