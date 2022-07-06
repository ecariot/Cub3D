/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:56:21 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/06 13:00:21 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// int	is_valid_texture(t_texture texture)
// {
// 	if (texture.north != NULL && texture.south != NULL && texture.west != NULL && texture.east != NULL)
// 		return (1);
// 	else
// 		return (0);
// }

// int	is_valid_color(t_texture texture)
// {
// 	if (texture.floor_b >= 0 && texture.floor_g >= 0 && texture.floor_r >= 0
// 		&& texture.ceiling_r >= 0 && texture.ceiling_g >= 0 && texture.ceiling_b >= 0)
// 		return (1);
// 	else
// 		return (0);
// }


// int	ft_check_texture(t_texture texture)
// {
// 	if (!is_valid_texture(texture))
// 		return (ft_errors("Texture is missing"));
// 	if (!is_valid_color(texture))
// 		return (ft_errors("Color is missing"));
// 	return (1);
// }

int	is_valid_texture(char **split_line)
{
	if (!split_line[1] || !split_line )
		return (ft_errors("Texture is missing"));
	if (split_line[2] != NULL)
		return (ft_errors("Too much texture"));
	return (0);
}
