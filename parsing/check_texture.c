/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:55:28 by mbascuna          #+#    #+#             */
/*   Updated: 2022/07/21 16:00:16 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_check_digits(char **format_color)
{
	int	i;
	int	tmp;

	i = 0;
	while (format_color[i])
	{
		tmp = ft_atoi(format_color[i]);
		if (tmp > 255 || tmp < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_texture(t_texture texture)
{
	if (!ft_texture_is_full(texture))
		return (ft_errors("Problem with texture"));
	if (texture.full == 1)
		return (ft_errors("Too Much texture"));
	if (!ft_color_is_full(texture))
		return (ft_errors("Problem with color"));
	return (0);
}

int	is_valid_texture(char **split_line)
{
	if (split_line[1] == NULL || !split_line)
		return (1);
	if (split_line[2] != NULL)
		return (1);
	return (0);
}

int	is_valid_digit(char **split_color)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (split_color[i])
	{
		tmp = ft_strtrim(split_color[i], ",");
		j = 0;
		while (tmp[j])
		{
			if (!ft_isdigit(tmp[j]) && tmp[j] != '\n')
			{
				free(tmp);
				return (1);
			}
			j++;
		}
		free(tmp);
		i++;
	}
	return (0);
}

int	is_valid_color(char **split_color)
{
	if (is_valid_digit(split_color) == 1)
		return (1);
	if (ft_strlen_tab(split_color) < 3)
		return (1);
	if (ft_strlen_tab(split_color) > 3)
		return (ft_errors("Too Much color"));
	if (!ft_check_digits(split_color))
		return (1);
	return (0);
}
