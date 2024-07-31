/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:07:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/30 18:32:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_path(t_map *map, int r, int c)
{
	if (r < 1 || r >= map->height - 1 || c < 1 || c >= map->width - 1
		|| map->map[r][c] == '1' || map->map[r][c] == 'V')
		return ;
	if (map->map[r][c] == 'P')
		map->elems.player--;
	else if (map->map[r][c] == 'C')
		map->elems.collectible--;
	else if (map->map[r][c] == 'E')
		map->elems.exit--;
	map->map[r][c] = 'V';
	fill_path(map, r, c - 1);
	fill_path(map, r - 1, c);
	fill_path(map, r, c + 1);
	fill_path(map, r + 1, c);
}

int	check_path(t_map *map)
{
	fill_path(map, map->start_r, map->start_c);
	if (map->elems.collectible == 0 && map->elems.exit == 0)
		return (1);
	else
		return (0);
}
