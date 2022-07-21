/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:12:44 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/21 16:02:16 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	exit_error(t_data *data, char *str)
{
	printf("Error: \n%s\n", str);
	if (data->cub.map)
		ft_free_tab(data->cub.map);
	ft_free_struct(data);
	close(data->fd);
	exit (0);
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

char	**ft_init_tab(t_data *data)
{
	char	**tab;
	int		tmp;

	tmp = data->cub.line;
	tab = (char **)malloc(sizeof(char *) * (data->cub.line + 1));
	if (!tab)
		return (NULL);
	tab[tmp] = NULL;
	return (tab);
}
