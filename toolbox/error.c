/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:12:44 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 11:13:17 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	exit_error(t_cub *cub, char *str)
{
	printf("Error: \n%s\n", str);
	// ft_free_struct(cub);
	// free_texture(cub);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	exit (0);
}
