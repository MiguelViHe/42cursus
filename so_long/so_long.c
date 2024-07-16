/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:03:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/16 18:33:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

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
	read_map(argv[1], &map);
	print_map_elems(map.elems);
	generate_map(argv[1], &map);
	print_map_array(map);
	free_map_array(&map);
	return (0);
}
