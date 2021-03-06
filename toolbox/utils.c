/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:54:39 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 15:55:41 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_free_struct(t_data *data)
{
	free(data->texture.south);
	free(data->texture.north);
	free(data->texture.east);
	free(data->texture.west);
}

int	close_window(t_data *data)
{
	ft_free_struct(data);
	ft_free_tab(data->cub.map);
	free_texture(&data->cub);
	if (data->cub.mlx_win)
		mlx_destroy_window(data->cub.mlx, data->cub.mlx_win);
	if (data->cub.mlx)
	{
		mlx_destroy_display(data->cub.mlx);
		free(data->cub.mlx);
	}
	exit(0);
}

char	*ft_replace_space_end(const char *s1, t_data *data)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * data->cub.col + 1);
	if (!str)
		return (NULL);
	i = 0;
	while ((size_t)i < ft_strlen(s1) - 1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < data->cub.col)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_no_n(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1));
	if (!str)
		return (NULL);
	i = 0;
	while ((size_t)i < ft_strlen(s1) - 1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_pic	*recup_wall(t_cub *cub)
{
	if (cub->side_wall == NORTH)
		return (&cub->w_no);
	if (cub->side_wall == SOUTH)
		return (&cub->w_so);
	if (cub->side_wall == EAST)
		return (&cub->w_ea);
	if (cub->side_wall == WEST)
		return (&cub->w_we);
	return (&cub->w_no);
}
