/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:16 by emcariot          #+#    #+#             */
/*   Updated: 2022/07/01 14:54:28 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_extension(char *file)
{
	char	*file_extension;
	int		extension_len;

	file_extension = ft_strrchr(file, '.');
	extension_len = ft_strlen(file_extension);
	if (ft_strncmp(".cub", file_extension, extension_len) != 0)
		return (1);
	return (0);
}
