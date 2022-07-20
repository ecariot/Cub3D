#include "../includes/cub.h"

void	ft_free_struct(t_data *data)
{
	free(data->texture.south);
	free(data->texture.north);
	free(data->texture.east);
	free(data->texture.west);
	ft_free_tab(data->cub.map);
}


int	close_window(t_data *data)
{
	ft_free_struct(data);
	free_texture(&data->cub);
	if (data->cub.mlx_win)
		mlx_destroy_window(data->cub.mlx, data->cub.mlx_win);
	if (data->cub.mlx)
	{
		mlx_destroy_display(data->cub.mlx);
		free(data->cub.mlx);
	}
	exit(0);
	// return (1);
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
	return (1);
}
