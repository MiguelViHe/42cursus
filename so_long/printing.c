/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:25:31 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/03 11:44:09 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_pos_map(t_map map)
{
	ft_printf("Positions map:\n");
	ft_printf("width = %i\n", map.width);
	ft_printf("height = %i\n", map.height);
	ft_printf("start_r = %i\n", map.start_r);
	ft_printf("start_c = %i\n", map.start_c);
	ft_printf("exit_r = %i\n", map.exit_r);
	ft_printf("exit_c = %i\n", map.exit_c);
	ft_printf("is_win = %i\n", map.is_win);
	ft_printf("moves = %i\n", map.moves);
}

void	print_map_array(t_map map)
{
	int	i;
	int	j;

	i = 0;
	if (map.map)
	{
		while (map.map[i])
		{
			j = 0;
			while (map.map[i][j] && map.map[i][j] != '\n')
			{
				ft_printf("[%c]", map.map[i][j]);
				j++;
			}
			ft_printf("\n");
			i++;
		}
	}
	else
		ft_printf("%s\n", map.map);
}

void	print_map_elems(t_map_elems map_elems)
{
	ft_printf("Map elems:\n");
	ft_printf("Wall = %i\n", map_elems.wall);
	ft_printf("Empty = %i\n", map_elems.empty);
	ft_printf("Player = %i\n", map_elems.player);
	ft_printf("collectible = %i\n", map_elems.collectible);
	ft_printf("exit = %i\n", map_elems.exit);
	ft_printf("enemy = %i\n", map_elems.enemy);
}

void	print_complete_map(t_map map)
{
	print_pos_map(map);
	print_map_elems(map.elems);
	print_map_array(map);
}
