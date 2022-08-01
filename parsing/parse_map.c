/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:15:43 by mbascuna          #+#    #+#             */
/*   Updated: 2022/08/01 11:52:13 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_if_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	ft_check_extension(char *file, char *extension)
{
	char	*file_extension;
	int		fd;

	fd = 0;
	file_extension = ft_strrchr(file, '.');
	if (!file_extension)
		return (ft_errors("Wrong extension"));
	if (check_if_directory(file))
		return (ft_errors("Invalid : is a directory"));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (ft_errors("Invalid File"));
	}
	if (ft_strcmp(extension, file_extension) != 0)
	{
		close (fd);
		return (ft_errors("Wrong extension"));
	}
	close(fd);
	return (0);
}

int	ft_is_map(char *line)
{
	int	len;
	int	i;

	i = 0;
	if (!line)
		return (0);
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

int	ft_check_buddies(int y, int x, char **map, t_data *data)
{
	if (y != 0 && (map[y - 1][x] == '0'
		|| ft_is_start(map[y - 1][x])))
		return (1);
	else if (x != 0 && (map[y][x - 1] == '0'
		|| ft_is_start(map[y][x - 1])))
		return (1);
	else if (x != data->cub.col && (map[y][x + 1] == '0'))
		return (1);
	else if (y != (data->cub.line - 1) && (map[y + 1][x] == '0'))
		return (1);
	return (0);
}

int	ft_pick_player(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_is_start(map[y][x]) && map[y][x] != '0')
			{
				if (data->cub.player == '\0')
				{
					data->cub.pos.x = x + 0.2;
					data->cub.pos.y = y + 0.2;
					data->cub.player = map[y][x];
				}
				else
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
