/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:22:00 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/05 13:22:03 by mbascuna         ###   ########.fr       */
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

char	*copy_line(char *line, t_data *data)
{
	int		i;
	char	*new_str;
	size_t	len;

	new_str = malloc(sizeof(char) * (data->cub.col + 1));
	if (!new_str)
		return (NULL);
	len = ft_strlen(line);
	i = 0;
	while (i < data->cub.col)
	{
		if (i >= (int)len)
			new_str[i] = ' ';
		else
			new_str[i] = line[i];
		i++;
	}
	new_str[i] = 0;
	free(line);
	return (new_str);
}

void	fill_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub.map[i])
	{
		data->cub.map[i] = copy_line(data->cub.map[i], data);
		i++;
	}
}

// char	**ft_add_line_in_map(char *line, char **map, t_data *data)
// {
// 	char	**new_map;
// 	int		i;

// 	i = data->cub.line;
// 	new_map = (char **)malloc(sizeof(char *) * i + 2);
// 	if (!new_map)
// 		return (NULL);
// 	new_map[i + 1] = NULL;
// 	new_map[i] = ft_strdup(line);
// 	while (i-- > 0)
// 	{
// 		new_map[i] = map[i];
// 	}
// 	return (new_map);
// }

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
	// data->cub.map = ft_add_line_in_map(line, data->cub.map);
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

//FAIRE EN SORTE QUE SI LIGNE VIDE >> PASSE A LA SUIVANTE TANT QUE CE NEST PAS LA FIN DU FICHIER
int ft_parse_element(t_data *data, char *file)
{
	char **split_line;
	char *get_line;
	int nb_line = 0;

	data->fd = open(file, O_RDONLY, 0);
	if (data->fd == -1)
		return (0);
	get_line = ft_get_next_line(data->fd);
	while (get_line)
	{
		// printf("nb line : %d\n", nb_line);
		nb_line++;
		split_line = ft_split_many(get_line, " ,");
		if (!ft_strcmp(split_line[0], "SO") || !ft_strcmp(split_line[0], "NO") ||
			!ft_strcmp(split_line[0], "WE") || !ft_strcmp(split_line[0], "EA"))
			{
				if (!ft_check_if_texture(split_line, data))
					return (0);
			}
		else if (!ft_strncmp(split_line[0], "F", 2) || !ft_strncmp(split_line[0], "C", 2))
		{
			if (!ft_check_if_color(split_line, data))
				return (0);
		}
		if (ft_color_is_full(data) && ft_texture_is_full(data))
		{
			close(data->fd);
			return (nb_line);
		}
		free(get_line);
		get_line = ft_get_next_line(data->fd);
	}
	close(data->fd);
	return (nb_line);
}

char	**ft_fill_map(t_data *data, char *file, int nb_line)
{
	char	*get_line;
	int line;
	int i = 0;

	data->cub.line -= nb_line;
	line = data->cub.line;
	data->cub.map = ft_init_tab(data);
	data->fd = open(file, O_RDONLY, 0);
	if (data->fd == -1)
		return (NULL);
	get_line = ft_get_next_line(data->fd);
	while (get_line && i < line)
	{
		data->cub.map[i] = ft_strdup(get_line);
		free(get_line);
		get_line = ft_get_next_line(data->fd);
		i++;
	}
	close(data->fd);
	return(data->cub.map);
}

int	ft_parsing(t_data *data, char *file)
{
	int i = 0;
	int nb_line = ft_parse_element(data, file);

	if (!nb_line)
	{
		close(data->fd);
		return (ft_errors("Invalid Elements"));
	}
	else
		data->cub.map = ft_fill_map(data, file, nb_line);
	// if (!ft_fill_map(data, file, nb_line))
	// {
	// 	close(data->fd);
	// 	return (ft_errors("Invalid Map"));
	// }
	printf("TEXTURE :\nNorth : %sSouth : %sWest : %sEast : %s", data->texture.north, data->texture.south, data->texture.east, data->texture.west);
	printf("COLOR FLOOR :\nfloor-R : %d\nfloor-G : %d\nfloor-B : %d\n", data->texture.floor_r, data->texture.floor_g, data->texture.floor_b);
	printf("COLOR CEILING :\nceiling-R : %d\nceiling-G : %d\nceiling-B : %d\n", data->texture.ceiling_r, data->texture.ceiling_g, data->texture.ceiling_b);
	printf("MAP :\n");
	while (data->cub.map[i++])
		printf("map : %s", data->cub.map[i]);
	return (0);
}
