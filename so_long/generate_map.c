/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:34:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/17 10:51:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_array(t_map *map)
{
	int	i;
	
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
		map->map = NULL;
}

void	initialize_start_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] && !(map->start_r && map->exit_r))
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j] != '\n' && !(map->start_r && map->exit_r))
		{
			if (map->map[i][j] == 'P')
			{
				map->start_r = i;
				map->start_c = j;
			}
			else if (map->map[i][j] == 'E')
			{
				map->exit_r = i;
				map->exit_c = j;
			}
			j++;
		}
		i++;
	}
}

void 	generate_map(char *map_name, t_map *map)
{
	int		fd;
	int		i;
	char	*buffer;

	fd = secure_open(map_name);
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (map->map == NULL)
		wrong_generate_map_exit("Error allocating memory for map array", fd);
	i = 0;
	buffer = get_next_line(fd);
	while(buffer)
	{
		map->map[i++] = buffer;
		buffer = get_next_line(fd);
	}
	if (i != map->height)
	{
		free_map_array(map);
		wrong_generate_map_exit("Error reading lines to generate the map", fd);
	}
	secure_close(fd);
	initialize_start_exit(map);
}
