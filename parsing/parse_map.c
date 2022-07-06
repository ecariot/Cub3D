/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:22:00 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/06 15:12:33 by mbascuna         ###   ########.fr       */
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

int	ft_is_map(char *line)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(line);
	if (!len)
		return (0);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
		|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
		return (0);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
			return (1);
		i++;
	}
	return (0);
}


// char	**ft_fill_map(t_data *data, char *file, char *get_line)
// {
// 	int line;
// 	int i = 0;
// 	(void)file;

// 	// data->cub.line -= nb_line - 1;
// 	line = data->cub.line;
// 	data->cub.map = ft_init_tab(data);
// 	while (i < line)
// 	{
// 		data->cub.map[i] = ft_strdup(get_line);
// 		free(get_line);
// 		get_line = ft_get_next_line(data->fd);
// 		i++;
// 	}
// 	data->cub.map[i] = NULL;
// 	// free(get_line);
// 	// close(data->fd);
// 	return(data->cub.map);
// }
