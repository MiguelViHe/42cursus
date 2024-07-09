/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:02:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/09 11:53:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	get_len_of_line(char *buffer)
{
	int	len;

	len = ft_strlen(buffer);
	if (buffer[len - 1] == '\n')
		return (len - 1);
	return (len);
}

char	*check_map_rectangular(int fd, char *buffer, size_t len_first_line)
{
	size_t	current_len;

	current_len = get_len_of_line(buffer);
	if (current_len != len_first_line)
		wrong_map_exit(buffer, "Error\nMap is not rectangular.", 1);
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
	fd = secure_open(map_name);
	buffer = get_next_line(fd);
	if (buffer == NULL)
		wrong_map_exit(buffer, "Error\nReading line from map or empty map.", 0);
	len_first_line = get_len_of_line(buffer);
	if (len_first_line < 3)
		wrong_map_exit(buffer, "Error\nLines at least 3 colums.", 1);
	while (buffer)
	{
		buffer = check_map_rectangular(fd, buffer, len_first_line);
		lines++;
	}
	secure_close(fd);
	if (lines < 3)
		wrong_map_exit(buffer, "Error\nThe map must have at least 3 lines.", 0);
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
