/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:19:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/18 10:46:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

	/*t_map_elems	*copy_map_elems()
	{
		t_map_elems	*copy_map_elems;
	}*/
	
	char	**copy_map_array(t_map *map)
	{
		char	**copy_array;
		int		i;

		copy_array = ft_calloc(map->height + 1, sizeof(char *));
		if (copy_array == NULL)
		{
			ft_fdprintf(2, "Error allocating memory for copy of map array");
			exit(EXIT_FAILURE);
		}
		i = 0;	
		while (map->map[i])
		{
			copy_array[i] = ft_calloc(map->width + 1, sizeof(char));
			if (copy_array[i] == NULL)
				wrong_copy_map_exit(copy_array, i);
			ft_strlcpy(copy_array[i], map->map[i], map->width + 1);
			i++;
		}
		return (copy_array);
	}

	/*t_map	copy_map(t_map map)
	{
		t_map		copy_map;

		ft_memset(&map_elems, 0, sizeof(t_map_elems));
		ft_memset(&map, 0, sizeof(t_map));
		map.elems = &map_elems;
	}*/