#include "../includes/cub.h"

int	ft_check_extension(char *file, char *extension)
{
	char	*file_extension;
	int		extension_len;
	int fd;

	fd = 0;
	file_extension = ft_strrchr(file, '.');
	if (!file_extension)
		return (return_error("Wrong extension"));
	extension_len = ft_strlen(file_extension);
	if ((fd = open(file, O_DIRECTORY)) != -1)
		return (ft_errors("Invalid : is a directory"));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_errors("Invalid File"));
	if (ft_strncmp(extension, file_extension, extension_len) != 0)
		return (ft_errors("Wrong extension"));
	return (0);
}

int	ft_is_map(char *line)
{
	int len;
	int i;

	i = 0;
	if (!line)
		return (0);
	len = ft_strlen(line);
	if (!len)
		return (0);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
		|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
		return (0);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
