/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:22:00 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/06 13:37:59 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_check_extension(char *file, char *extension)
{
	char	*file_extension;
	int		extension_len;
	int fd;

	fd = 0;
	file_extension = ft_strrchr(file, '.');
	extension_len = ft_strlen(file_extension);
	if ((fd = open(file, O_DIRECTORY)) != -1)
		return (ft_errors("Invalid : is a directory"));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_errors("Invalid File"));
	if (ft_strncmp(extension, file_extension, extension_len) != 0)
		return (ft_errors("Wrong extension"));
	return (0);
}

int	ft_check_line(char *line, t_data *data)
{
	int len;
	int i;
	(void)data;

	i = 0;
	len = ft_strlen(line);
	if (!line)
		return (0);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
		|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
		return (0);
	else if (ft_strncmp(&line[i], "1", 1) || ft_strncmp(&line[len - 2], "1", 1))
		return (2);
	return (1);
}

int	ft_texture_is_full(t_data *data)
{
	if (data->texture.north != NULL && data->texture.south != NULL &&
		data->texture.west != NULL && data->texture.east != NULL)
			return (1);
	return (0);
}

int	ft_color_is_full(t_data *data)
{
	if (data->texture.floor_b != 0 && data->texture.floor_r != 0 &&
		data->texture.floor_r != 0 && data->texture.ceiling_r != 0 &&
		data->texture.ceiling_g != 0 && data->texture.ceiling_b != 0)
			return (1);
	return (0);
}

char	**ft_fill_map(t_data *data, char *file, int nb_line, char *get_line)
{
	int line;
	int i = 0;
	(void)file;

	data->cub.line -= nb_line - 1;
	line = data->cub.line;
	data->cub.map = ft_init_tab(data);
	while (i < line - 1)
	{
		data->cub.map[i] = ft_strdup(get_line);
		free(get_line);
		get_line = ft_get_next_line(data->fd);
		i++;
	}
	free(get_line);
	close(data->fd);
	return(data->cub.map);
}

int ft_parse_elements(t_data *data, char *file)
{
	char **split_line;
	char *get_line;
	int nb_line = 0;

	data->fd = open(file, O_RDONLY, 0);
	if (data->fd == -1)
		return (0);
	while (get_line)
	{
		get_line = ft_get_next_line(data->fd);
		split_line = ft_split_many(get_line, " ,");
		if (!split_line)
		{
			printf("HELLO\n");
			ft_free_tab(split_line);
		}
		if (ft_is_texture(split_line))
		{
			if (is_valid_texture(split_line))
				return (1);
			if (!ft_parse_texture(split_line, data))
				return (ft_errors("Texture already exist"));
		}
		else if (!ft_strncmp(split_line[0], "F", 2) || !ft_strncmp(split_line[0], "C", 2))
		{
			if (!ft_check_if_color(split_line, data))
				return (1);
		}
		else if (ft_color_is_full(data) && get_line[0] != '\n')
		{
			data->cub.map = ft_fill_map(data, file, nb_line, get_line);
			return (0);
		}
		nb_line++;
		free(get_line);
	}
	close(data->fd);
	return (0);
}


int	ft_parsing(t_data *data, char *file)
{
	// int i;

	// i = 0;
	if (ft_parse_elements(data, file))
	{
		close(data->fd);
		return (1);
	}
	if (!ft_check_map(data->cub))
	{
		return (1);
	}
	printf("TEXTURE :\nNorth : %sSouth : %sWest : %sEast : %s", data->texture.north, data->texture.south, data->texture.west, data->texture.east);
	printf("COLOR FLOOR :\nfloor-R : %d\nfloor-G : %d\nfloor-B : %d\n", data->texture.floor_r, data->texture.floor_g, data->texture.floor_b);
	printf("COLOR CEILING :\nceiling-R : %d\nceiling-G : %d\nceiling-B : %d\n", data->texture.ceiling_r, data->texture.ceiling_g, data->texture.ceiling_b);
	printf("MAP :\n");
	// while (data->cub.map[i])
	// {
	// 	printf("map : %s", data->cub.map[i]);
	// 	i++;
	// }
	return (0);
}
