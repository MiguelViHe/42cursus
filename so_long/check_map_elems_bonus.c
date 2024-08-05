/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elems_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:26:57 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 20:18:45 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ok_num_of_elems(t_map *map, t_map_elems *m_elem)
{
	if (m_elem->player == 1 && m_elem->collectible >= 1 && m_elem->exit == 1)
	{
		if (m_elem->enemy > 0 && (map->width < 4 || map->height < 4))
		{
			ft_fdprintf(2, "Error\n Size map with enemies (4 rows or lines)\n");
			exit (EXIT_FAILURE);
		}
		return (1);
	}
	else
		return (0);
}

static int	is_char_in_elems(char c, t_map_elems *map_elems)
{
	if (c == '0')
		map_elems->empty++;
	else if (c == '1')
		map_elems->wall++;
	else if (c == 'P')
		map_elems->player++;
	else if (c == 'C')
		map_elems->collectible++;
	else if (c == 'E')
		map_elems->exit++;
	else if (c == 'X')
		map_elems->enemy++;
	else
		return (0);
	return (1);
}

static void	check_middle(char *buffer, t_map_elems *map_elems)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		if (i == 0 || i == (get_len_of_line(buffer) - 1))
		{
			if (buffer[i] != '1')
				wrong_map_exit(buffer, "Error\nInvalid boundary elements.", 1);
			map_elems->wall++;
		}
		else
			if (!is_char_in_elems(buffer[i], map_elems))
				wrong_map_exit(buffer, "Error\nInvalid elements in map.", 1);
		i++;
	}
}

static void	check_up_down(char *buffer, t_map_elems *map_elems)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		if (buffer[i] != '1')
			wrong_map_exit(buffer, "Error\nIncorrect boundary elements.", 1);
		map_elems->wall++;
		i++;
	}
}

void	check_map_elems(char *map_name, t_map *map)
{
	int			fd;
	char		*buffer;
	int			current_line;

	fd = secure_open(map_name);
	buffer = get_next_line(fd);
	if (buffer == NULL)
		wrong_map_exit(buffer, "Error\nReading line from map.", 0);
	current_line = 1;
	while (buffer)
	{
		if (current_line == 1 || current_line == map->height)
			check_up_down(buffer, &map->elems);
		else
			check_middle(buffer, &map->elems);
		current_line++;
		free (buffer);
		buffer = get_next_line(fd);
	}
	secure_close(fd);
	if (!ok_num_of_elems(map, &map->elems))
		wrong_map_exit(buffer, "Error\nwith necessary elements in map.", 0);
}
