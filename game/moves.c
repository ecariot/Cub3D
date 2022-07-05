/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:11:27 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/05 13:53:31 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	keycode(int key, t_cub *cub)
{
	if (key == 65307)
		close_window(cub);
	// if (key == 119)
	// 	//fonction movforward
	// if (key == 115)
	// 	//fonction moveback
	// if (key == 110)
	// 	//move right
	// if (key == 113)
	// 	//move left
	return (0);
}
