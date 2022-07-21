/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:10:13 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 16:34:25 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_stop_read(int fd)
{
	ft_errors("Empty file");
	close(fd);
	return (1);
}

int	ft_read_map(t_data *data, char *file)
{
	char	*get_line;
	int		fd;

	fd = open(file, O_RDONLY);
	get_line = ft_get_next_line(fd);
	if (!get_line)
		ft_stop_read(fd);
	data->cub.col = ft_strlen(get_line);
	data->cub.line = 0;
	while (get_line)
	{
		free(get_line);
		get_line = ft_get_next_line(fd);
		if (ft_is_map(get_line))
		{
			data->cub.line++;
			if ((ft_strlen(get_line) > (size_t)data->cub.col))
				data->cub.col = ft_strlen(get_line) - 1;
		}
	}
	close(fd);
	return (0);
}
