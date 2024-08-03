/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:19:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/03 11:36:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map_elems(t_map map, t_map_elems *copy_map_elems)
{
	copy_map_elems->empty = map.elems.empty;
	copy_map_elems->wall = map.elems.wall;
	copy_map_elems->collectible = map.elems.collectible;
	copy_map_elems->exit = map.elems.exit;
	copy_map_elems->player = map.elems.player;
	copy_map_elems->enemy = map.elems.enemy;
}

void	initialize_copy_map(t_map map, t_map *copy_map)
{
	copy_map->width = map.width;
	copy_map->height = map.height;
	copy_map->start_r = map.start_r;
	copy_map->start_c = map.start_c;
	copy_map->exit_r = map.exit_r;
	copy_map->exit_c = map.exit_c;
	copy_map->is_win = map.is_win;
	copy_map->moves = map.moves;
}

char	**copy_map_array(t_map map)
{
	char	**copy_array;
	int		i;

	copy_array = ft_calloc(map.height + 1, sizeof(char *));
	if (copy_array == NULL)
	{
		ft_fdprintf(2, "Error allocating memory for copy of map array");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (map.map[i])
	{
		copy_array[i] = ft_calloc(map.width + 1, sizeof(char));
		if (copy_array[i] == NULL)
			wrong_copy_map_exit(copy_array, i);
		ft_strlcpy(copy_array[i], map.map[i], map.width + 1);
		i++;
	}
	return (copy_array);
}

t_map	copy_map(t_map map)
{
	t_map	copy_map;

	ft_memset(&copy_map, 0, sizeof(t_map));
	copy_map_elems(map, &copy_map.elems);
	initialize_copy_map(map, &copy_map);
	copy_map.map = copy_map_array(map);
	return (copy_map);
}
