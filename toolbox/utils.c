/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:30:35 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/12 12:20:30 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free (map[i]);
	// return (NULL);
}

int	free_textures(t_cub *cub)
{
	if (cub->screen.img)
		mlx_destroy_image(cub->mlx, cub->screen.img);
	if (cub->w_no.img)
		mlx_destroy_image(cub->mlx, cub->w_no.img);
	if (cub->w_so.img)
		mlx_destroy_image(cub->mlx, cub->w_so.img);
	if (cub->w_ea.img)
		mlx_destroy_image(cub->mlx, cub->w_ea.img);
	if (cub->w_we.img)
		mlx_destroy_image(cub->mlx, cub->w_we.img);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	free_map(cub->map);
	// printf("je suis arrivee au bout de free texture\n");
	return (1);
}

int	close_window(t_cub *cub)
{
	free_textures(cub);
	return (mlx_loop_end(cub->mlx));

}

char	*ft_strdup_no_n(const char *s1)
{
	char	*str;
	int		i;


	str = (char *)malloc(sizeof(char) * (ft_strlen(s1)));
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
