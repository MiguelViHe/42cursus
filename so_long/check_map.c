/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:02:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/08 19:40:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

char	*check_map_rectangular(int fd, char *buffer, size_t len_first_line)
{
	if (ft_strlen(buffer) != len_first_line)
			wrong_map_exit(buffer, "Error\nMap is not rectangular.\n", 1);
		free(buffer);
		return (get_next_line(fd));
}

int	check_shape_map(char *map_name)
{
	int		fd;
	int		lines;
	char	*buffer;
	size_t	len_first_line;

	buffer = NULL;
	lines = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		wrong_map_exit(buffer, "Error opening file.\n", 0);
	buffer = get_next_line(fd);
	if (buffer == NULL)
			wrong_map_exit(buffer, "Error\nReading line from map or empty map.", 0);
	len_first_line = ft_strlen(buffer);
	if (len_first_line < 3)
			wrong_map_exit(buffer, "Error\nLines at least 3 colums.\n", 1);
	while (buffer)
	{
		buffer = check_map_rectangular(fd, buffer, len_first_line);
		lines++;
	}
	if (lines < 3)
		wrong_map_exit(buffer, "Error\nThe map must have at least 3 lines.\n", 0);
	return (lines);
}

//void	read_map(char *map_name, t_map_elems map_elems)
void	read_map(char *map_name)
{
	int		map_lines;

	map_lines = check_shape_map(map_name);
	ft_printf("map_lines = %d\n", map_lines);
	//check_map_elems(map_name, map_lines, t_map_elems)
}