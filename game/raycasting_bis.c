/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:20:01 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 15:33:38 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_step_and_side(t_cub *cub)
{
	if (cub->raydir.x < 0.)
	{
		cub->step.x = -1.0;
		cub->sidedist.x = (cub->pos.x - cub->tab.x) * cub->deltadist.x;
	}
	else
	{
		cub->step.x = 1.0;
		cub->sidedist.x = (cub->tab.x + 1.0 - cub->pos.x) * cub->deltadist.x;
	}
	if (cub->raydir.y < 0.)
	{
		cub->step.y = -1.0;
		cub->sidedist.y = (cub->pos.y - cub->tab.y) * cub->deltadist.y;
	}
	else
	{
		cub->step.y = 1.0;
		cub->sidedist.y = (cub->tab.y + 1.0 - cub->pos.y) * cub->deltadist.y;
	}
}

void	perform_dda_help_bis(t_cub *cub)
{
	if (cub->raydir.y < 0.0)
		cub->side_wall = EAST;
	else
		cub->side_wall = WEST;
}

void	perform_dda_help(t_cub *cub)
{
	if (cub->raydir.x < 0.0)
		cub->side_wall = NORTH;
	else
		cub->side_wall = SOUTH;
}

int	perform_dda(t_cub *cub)
{
	int	side;

	side = 0;
	while (cub->hit == 0)
	{
		if (cub->sidedist.x < cub->sidedist.y)
		{
			cub->sidedist.x += cub->deltadist.x;
			cub->tab.x += cub->step.x;
			side = 0;
			perform_dda_help(cub);
		}
		else
		{
			cub->sidedist.y += cub->deltadist.y;
			cub->tab.y += cub->step.y;
			side = 1;
			perform_dda_help_bis(cub);
		}
		if (cub->map[(int)cub->tab.y][(int)cub->tab.x] == '1')
			cub->hit = 1;
	}
	return (side);
}
