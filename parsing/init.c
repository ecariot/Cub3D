
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
	data->cub.player = 0;
	data->cub.line = 0;
	data->cub.col = 0;
	data->cub.win_width = 0;
	data->cub.win_height = 0;
	data->cub.dir.x = 0;
	data->cub.dir.y = 0;
	data->cub.pos.x = 0;
	data->cub.pos.y = 0;
	data->cub.plane.x = 0;
	data->cub.plane.y = 0;
	data->cub.raydir.x = 0;
	data->cub.raydir.y = 0;
	data->cub.sidedist.x = 0;
	data->cub.sidedist.y = 0;
	data->cub.step.x = 0;
	data->cub.step.y = 0;
	data->cub.tab.x = 0;
	data->cub.tab.y = 0;
	data->cub.camerax = 0;
	data->cub.wallx = 0.0;
	data->cub.hit = 0;
	data->cub.map = NULL;
	// data->cub.w_no.height = 0;
	// data->cub.w_no.width = 0;
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
			data->cub.col = ft_strlen(get_line) - 1;
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
	tab[tmp] = NULL;
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
