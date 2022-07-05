/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:40:17 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/05 09:31:19 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../mlx_linux/mlx.h"

void	init_texture(t_cub *cub)
{
	cub->walls.img = mlx_xpm_file_to_image(cub->mlx,
		 "../textures/redbrick_1.xpm", &cub->walls.width, &cub->walls.height);
	if (!cub->walls.img)
		return_error("Missing texture\n");

}
