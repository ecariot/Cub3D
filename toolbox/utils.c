#include "../includes/cub.h"

int	close_window(t_cub *cub)
{
	// ft_free_tab(cub->map);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	// free_texture(cub);
	return (mlx_loop_end(cub->mlx));
}

char	*ft_replace_space_end(const char *s1, t_data *data)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * data->cub.col + 1);
	if (!str)
		return (NULL);
	i = 0;
	while ((size_t)i < ft_strlen(s1) - 1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i <  data->cub.col)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_no_n(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1));
	if (!str)
		return (NULL);
	i = 0;
	while ((size_t)i < ft_strlen(s1) - 1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	free_texture(t_cub *cub)
{
	if (cub->w_no.img)
		mlx_destroy_image(cub->mlx, cub->w_no.img);
	if (cub->w_so.img)
		mlx_destroy_image(cub->mlx, cub->w_so.img);
	if (cub->w_ea.img)
		mlx_destroy_image(cub->mlx, cub->w_ea.img);
	if (cub->w_we.img)
		mlx_destroy_image(cub->mlx, cub->w_we.img);
	if (cub->screen.img)
		mlx_destroy_image(cub->mlx, cub->screen.img);
    // if (cub->mlx)
    // {
    //     mlx_destroy_display(cub->mlx);
    //     free(cub->mlx);
    // }
    // ft_free_tab(cub->map);
    return (1);
}
