#include "../includes/cub.h"

int	ft_check_extension(char *file, char *extension)
{
	char	*file_extension;
	int		extension_len;
	int fd;

	fd = 0;
	file_extension = ft_strrchr(file, '.');
	if (!file_extension)
		return (ft_errors("Wrong extension"));
	extension_len = ft_strlen(file_extension);
	if ((fd = open(file, O_DIRECTORY)) != -1)
	{
		close(fd);
		return (ft_errors("Invalid : is a directory"));
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		close(fd);
		return (ft_errors("Invalid File"));
	}
	if (ft_strncmp(extension, file_extension, extension_len) != 0)
	{
		close (fd);
		return (ft_errors("Wrong extension"));
	}
	close(fd);
	return (0);
}

int	ft_is_map(char *line)
{
	int len;
	int i;

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

char	**ft_replace_space_inside(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->cub.line)
	{
		x = 0;
		while (x <= data->cub.col)
		{
			if (ft_isspace(map[y][x]))
			{
				if (ft_check_buddies(y, x, map, data))
					return (ft_free_tab(map));
				else
					map[y][x] = '1';
			}
			x++;
		}
		y++;
	}
	return (map);
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
					data->cub.pos.x = x;
					data->cub.pos.y = y;
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
