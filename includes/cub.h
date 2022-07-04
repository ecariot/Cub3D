/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:39:51 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/04 15:18:54 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>


typedef struct s_texture
{
	void	*img;
	int	height;
	int	width;
}	t_texture;

typedef struct s_data
{
	int	fd;
	t_texture	texture;
}	t_data;

typedef struct s_cub
{
	void	*mlx;
	void	*mlx_win;
	int	posX;
	int	posY;
	int	dirX;
	int	dirY;
	int	width;
	int	height;
	t_texture	walls;
	t_texture	sky;
	t_texture	floor;
}	t_cub;

//PARSING
int	check_extension(char *file);

//GAME
void	return_error(char *str);
int		keycode(int key, t_cub *cub);

#endif
