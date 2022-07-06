/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:26:25 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/06 12:47:24 by emcariot         ###   ########.fr       */
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
# include "../mlx_linux/mlx_int.h"

typedef struct s_pic
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_pic;

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
	int	endian;
	int	*width;
	int	*height;
} t_texture;

typedef struct s_cub
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int	posX;
	int	posY;
	int	dirX;
	int	dirY;
	int	width;
	int	height;
	int line;
	int col;
	int	w;
	int	h;
	int	x;
	int	y;
	t_pic	w_no;
	t_pic	w_so;
	t_pic	w_ea;
	t_pic	w_we;
}	t_cub;

typedef struct s_data
{
	int		fd;
	void	*mlx;
	void	*win;
	void	*img;
	t_texture	texture;
	t_cub		cub;
}	t_data;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

//PARSING
int	ft_check_extension(char *file, char *extension);
int	ft_parsing(t_data *data, char *file);
int ft_parse_element(t_data *data, char *file);
int	ft_check_line(char *line, t_data *data);
char	**ft_add_line_in_map(char *line, char **map, t_data *data);

/** parse_texture.c **/
void	ft_parse_color(char **format_color, t_data *data);
int ft_check_digits(char **format_color);
int	ft_check_if_color(char **line, t_data *data);
void	ft_parse_texture(char **format_texture, t_data *data);
int	ft_check_if_texture(char **line, t_data *data);

void ft_init_texture(t_data *data);
void ft_init_cub(t_data *data);
int	ft_errors(char *str);
char	**ft_init_tab(t_data *data);
void	ft_read_map(t_data *data, char *file);


//GAME
int		keycode(int key, t_cub *cub);
int		init_cub(t_cub *cub);
void	init_struct(t_cub *cub);
int		draw_window(t_cub *cub);
int	put_img(t_cub *cub);

//ERROR
int		ft_errors(char *str);
int		return_error(char *str);

//UTILS
int	close_window(t_cub *cub);

#endif
