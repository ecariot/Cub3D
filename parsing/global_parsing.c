#include "../includes/cub.h"

int ft_parse_elements(t_data *data, char *file)
{
	char **split_line;
	char **split_color;
	char *get_line;
	int i = 0;

	data->fd = open(file, O_RDONLY, 0);
	if (data->fd == -1)
		return (1);
	get_line = ft_get_next_line(data->fd);
	while (get_line)
	{
		split_line = ft_split_many(get_line, " ");
		// printf("split_line[0] : %s\n", split_line[0]);
		if (ft_is_texture(split_line))
		{
			if (is_valid_texture(split_line))
			{
				free(get_line);
				ft_free_tab(split_line);
				return (1);
			}
			if (ft_parse_texture(split_line, data))
			{
				free(get_line);
				ft_free_tab(split_line);
				return (1);
			}
		}
		else if (ft_is_color(split_line))
		{
			if (ft_strlen_tab(split_line) > 2)
			{
				int i = 2;
				while (split_line[i])
				{
					split_line[1] = ft_strjoin(split_line[1], split_line[i]);
					i++;
				}
			}
			split_color = ft_split_many(split_line[1], " ,");
			if (is_valid_color(split_color))
			{
				ft_free_tab(split_line);
				free(get_line);
				return (1);
			}
			if (ft_parse_color(split_line, split_color, data))
				return (1);
		}
		else if (ft_is_map(get_line) && get_line[0] != '\n')
		{
			data->cub.map = ft_init_tab(data);
			while (i < data->cub.line)
			{
				data->cub.map[i] = ft_replace_space_end(get_line, data);
				free(get_line);
				get_line = ft_get_next_line(data->fd);
				i++;
			}
			data->cub.map[i] = NULL;
		}
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
		return (1);
	}
	if (ft_check_map(data))
	{
		ft_free_tab(data->cub.map);
		return (1);
	}
	return (0);
}
