/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:03:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/15 10:51:09 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

void	print_map_elems(t_map_elems *map_elems)
{
	ft_printf("Wall = %i\n", map_elems->wall);
	ft_printf("Empty = %i\n", map_elems->empty);
	ft_printf("Player = %i\n", map_elems->player);
	ft_printf("collectible = %i\n", map_elems->collectible);
	ft_printf("exit = %i\n", map_elems->exit);
}

int	main(int argc, char *argv[])
{
	t_map_elems	map_elems;
	t_map		map;

	ft_memset(&map_elems, 0, sizeof(t_map_elems));
	ft_memset(&map, 0, sizeof(t_map));
	map.elems = &map_elems;
	if (argc != 2)
	{
		ft_fdprintf(2, "Num args Error\n Try: %s name_map.ber\n", argv[0]);
		return (-1);
	}
	check_arg_ber(argv[1]);
	read_map(argv[1], map.elems, &map);
	print_map_elems(map.elems);
	return (0);
}
