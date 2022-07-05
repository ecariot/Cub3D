/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:53:46 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/05 12:34:03 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

typedef struct s_texture
{
	char *north;
	char *south;
	char *east;
	char *west;
	int	floor_r;
	int	floor_g;
	int	floor_b;
	int	ceiling_r;
	int	ceiling_g;
	int	ceiling_b;
	int fd;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_len;
	int	endian;

} t_texture;

typedef struct s_cub
{
    void    *mlx;
	void	*mlx_win;
	char **map;
	int	posX;
	int	posY;
	int	dirX;
	int	dirY;
	int	w;
	int	h;
	t_texture	screen;
}    t_cub;

typedef struct s_data
{
	int		fd;
	void	*mlx;
	void	*win;
	t_texture	texture;
	t_cub		cub;
}	t_data;


//PARSING
int	ft_check_extension(char *file, char *extension);
int	ft_parsing(t_data *data);
int ft_fill_map(t_data *data);
int	ft_check_line(char *line, t_data *data);
char	**ft_add_line_in_map(char *line, char **map);

/** parse_texture.c **/
void	ft_parse_color(char **format_color, t_data *data);
int ft_check_digits(char **format_color);
int	ft_check_if_color(char *line, t_data *data);
void	ft_parse_texture(char **format_texture, t_data *data);
int	ft_check_if_texture(char *line, t_data *data);




//GAME
int		keycode(int key, t_cub *cub);
int		init_cub(t_cub *cub);
void	init_struct(t_cub *cub);
int	draw_window(t_cub *cub);

//ERROR
int		ft_errors(char *str);
int	return_error(char *str);

//UTILS
int	close_window(t_cub *cub);

#endif
