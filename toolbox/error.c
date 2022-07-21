/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:12:44 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 12:10:07 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	exit_error(t_data *data, char *str)
{
	printf("Error: \n%s\n", str);
	ft_free_struct(data);
	ft_free_tab(data->cub.map);
	// free_texture(data);
	if (data->cub.mlx_win)
		mlx_destroy_window(data->cub.mlx, data->cub.mlx_win);
	if (data->cub.mlx)
	{
		mlx_destroy_display(data->cub.mlx);
		free(data->cub.mlx);
	}
	exit (0);
}
