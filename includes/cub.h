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

typedef enum e_side_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_side_wall;

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
	// int fd;
	// int	endian;
	// int	*width;
	// int	*height;
} t_texture;

typedef struct	s_coord
{
	double x;
	double y;
} t_coord;

typedef struct s_cub
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int	win_width;
	int	win_height;
	t_coord	pos;
	t_coord	tab;
	t_coord	dir;
	t_coord	raydir;
	t_coord	sidedist;
	t_coord	deltadist;
	t_coord	step;
	t_coord plane;
	int line;
	int col;
	char player;
	double camerax;
	double wallx;
	double	wall_len;
	int	hit;
	int	rotate_r;
	int	rotate_l;
	int left;
	int right;
	int down;
	int forward;
	t_pic	screen;
	t_pic	w_no;
	t_pic	w_so;
	t_pic	w_ea;
	t_pic	w_we;
	t_side_wall		side_wall;
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

//PARSING
/** global_parsing.c **/
int	ft_parsing(t_data *data, char *file);
int ft_parse_element(t_data *data, char *file);

/** parse_map. **/
int	ft_check_extension(char *file, char *extension);
int	ft_is_map(char *line);
char	**ft_fill_map(t_data *data, char *file, char *get_line);

/** parse_texture.c **/
int ft_is_texture(char **split_line);
int ft_is_color(char **split_line);
int	ft_parse_texture(char **split_line, t_data *data);
int	ft_parse_color(char **format_color, t_data *data);

/** check_map.c **/
int	ft_check_map(t_data *data);
int	ft_check_if_close(char **map);
int ft_check_char(char **map);
int ft_is_start(char c);
int is_valid_char(char c);

/** check_texture.c **/
int ft_check_digits(char **format_color);
int	ft_color_is_full(t_texture texture);
int	ft_texture_is_full(t_texture texture);
int	ft_check_texture(t_texture texture);
int	is_valid_texture(char **split_line);
int	is_valid_color(char **split_line);

/** init.c **/
void ft_init_texture(t_data *data);
void ft_init_cub(t_data *data);
char	**ft_init_tab(t_data *data);
void	ft_read_map(t_data *data, char *file);
void	init_player(t_cub *cub);

//GAME
int		init_cub(t_cub *cub);
void	init_struct(t_cub *cub);
int		draw_window(t_cub *cub, t_data *data);
int	put_img(t_data *data);
int	fill_wall_north(char **split_line, t_data *data);

/** raycasting.c **/
int init_raycasting(t_cub *cub, t_data *data);
int	perform_dda(t_cub *cub);
void init_step_and_side(t_cub *cub);
int	create_trgb(int t, int r, int g, int b);
void	draw_ceiling(t_cub *cub, t_data *data, int x, int y);
void	rotate_left(t_cub *cub);
void	rotate_right(t_cub *cub);
int	go_one(int key, t_data *data);
int	keycode(int key, t_cub *cub);
int	reset_key(int key, t_data *data);

//ERROR
int		ft_errors(char *str);
int		return_error(char *str);

//UTILS
int	close_window(t_cub *cub);
char	*ft_strdup_no_n(const char *s1);

#endif
