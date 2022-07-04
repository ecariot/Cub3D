/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:16 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/04 13:58:50 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// int	check_extension(char *file, t_data *data)
// {
// 	char	*file_extension;
// 	int		extension_len;

// 	file_extension = ft_strrchr(file, '.');
// 	extension_len = ft_strlen(file_extension);
// 	if ((data->fd = open(file, O_DIRECTORY)) != -1)
// 		return (ft_errors("Invalid : is a directory"));
// 	if ((data->fd = open(file, O_RDONLY)) == -1)
// 		return (ft_errors("Invalid File"));
// 	if (ft_strncmp(".cub", file_extension, extension_len) != 0)
// 		return (ft_errors("Wrong extension"));
// 	return (0);
// }

// int	ft_check_line(char *line)
// {
// 	int len;

// 	len = ft_strlen(line);
// 	if (!line)
// 		return (1);
// 	while (ft_isspace(line[i]))
// 		i++;
// 	if (ft_strcmp(line[i], "1") || ft_strcmp(line[len - 1], "1"))
// 		return (1);
// 	return (0);
// }

// char	**ft_check_if_texture(char *line)
// {
// 	char **format_texture;

// 	if (!line)
// 		return (NULL);
// 	format_texture = ft_split(line, ' ');
// 	if (!format_texture || format_texture[2] != NULL)
// 	{
// 		free(format_texture);
// 		return (NULL);
// 	}
// 	if (ft_strcmp(format_texture[0], "SO") || ft_strcmp(format_texture[0], "NO") ||
// 		ft_strcmp(format_texture[0], "WE") || ft_strcmp(format_texture[0], "EA"))
// 	{
// 		free(format_texture);
// 		return (NULL);
// 	}
// 	return (format_texture);
// }

// void	ft_parse_texture(char **format_texture, t_data *data)
// {

// }

// char **ft_fill_map(t_data *data)
// {
// 	char	*get_line;
// 	char	**format_texture;

// 	get_line = ft_get_next_line(data->fd);
// 	if (!get_line)
// 		return (NULL);
// 	while (get_line)
// 	{
// 		// si c'est un texture , faire parsing texture et passer a la ligne dapres
// 		format_texture = ft_check_if_texture(get_line);
// 		if (format_texture != NULL)
// 			ft_parse_texture(format_texture, data);
// 		// si cest une couleur, faire parsing couleur et passer a la ligne dapres
// 		// si cest des chiffres, faire parsing map et passer a la ligne suivante
// 		else if (ft_check_line(get_line))
// 			return (NULL);
// 	}

// }

// void	ft_parsing(t_data *data)
// {
// 	if (!ft_fill_map(data))
// 	{
// 		close(fd);
// 		return (ft_errors("Invalid Map"));
// 	}
// }
