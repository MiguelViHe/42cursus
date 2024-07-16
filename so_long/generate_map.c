/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:34:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/16 18:14:20 by mvidal-h         ###   ########.fr       */
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

void 	generate_map(char *map_name, t_map *map)
{
	int		fd;
	int		i;
	char	*buffer;

	fd = secure_open(map_name);
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (map->map == NULL)
	{
		ft_fdprintf(2, "Error allocating memory for map array\n");
		secure_close(fd);
		exit(-1);
	}
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
		ft_fdprintf(2, "Error reading lines to generate the map array\n");
	}
	secure_close(fd);
}
