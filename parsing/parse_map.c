/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:52:22 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/04 16:52:47 by mbascuna         ###   ########.fr       */
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

char	**ft_add_line_in_map(char *line, char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	while (map[i])
		i++;
	new_map = (char **)malloc(sizeof(char *) * i + 1);
	if (!new_map)
		return (NULL);
	new_map[i] = NULL;
	new_map[--i] = ft_strdup(line);
	while (--i > 0)
		new_map[i] = map[i];
	return (new_map);
}

int	ft_check_line(char *line, t_data *data)
{
	int len;
	int i;

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
	data->cub.map = ft_add_line_in_map(line, data->cub.map);
	return (1);
}

//FAIRE EN SORTE QUE SI LIGNE VIDE >> PASSE A LA SUIVANTE TANT QUE CE NEST PAS LA FIN DU FICHIER
int ft_fill_map(t_data *data)
{
	char	*get_line;

	get_line = ft_get_next_line(data->fd);
	if (!get_line)
		return (0);
	while (get_line)
	{
		// si c'est un texture , faire parsing texture et passer a la ligne dapres
		// si cest une couleur, faire parsing couleur et passer a la ligne dapres
		// si cest des chiffres, faire parsing map et passer a la ligne suivante
		if (ft_check_if_texture(get_line, data) == 2)
			return (0);
		else if (ft_check_if_color(get_line, data) == 2)
			return (0);
		else if (ft_check_line(get_line, data) == 2)
			return (0);
		free(get_line);
		get_line = ft_get_next_line(data->fd);
	}
	return (1);
}

int	ft_parsing(t_data *data)
{
	int i = 0;
	if (!ft_fill_map(data))
	{
		close(data->fd);
		return (ft_errors("Invalid Map"));
	}
	printf("TEXTURE :\nNorth : %sSouth : %sWest : %sEast : %s", data->texture.north, data->texture.south, data->texture.east, data->texture.west);
	printf("COLOR FLOOR :\nfloor-R : %d\nfloor-G : %d\nfloor-B : %d\n", data->texture.floor_r, data->texture.floor_g, data->texture.floor_b);
	printf("COLOR CEILING :\nceiling-R : %d\nceiling-G : %d\nceiling-B : %d\n", data->texture.ceiling_r, data->texture.ceiling_g, data->texture.ceiling_b);
	printf("MAP :\n");
	while (data->cub.map[i++])
		printf("map : %s\n", data->cub.map[i]);
	return (0);
}
