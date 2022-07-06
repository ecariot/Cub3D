/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:30:35 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/06 15:59:38 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	close_window(t_cub *cub)
{
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
