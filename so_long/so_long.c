/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:03:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/18 17:00:55 by mvidal-h         ###   ########.fr       */
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
	ft_printf("moves = %i\n", map.moves);
}

void	print_copy_map_array(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				ft_printf("[%c]", map[i][j]);
				j++;
			}
			ft_printf("\n");
			i++;
		}
	}
	else
		ft_printf("%s\n", map);
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
}

void	print_complete_map(t_map map)
{
	print_pos_map(map);
	print_map_elems(map.elems);
	print_map_array(map);
}

int	main(int argc, char *argv[])
{
	t_map		map;
	t_map		c_map;

	ft_memset(&map, 0, sizeof(t_map));
	if (argc != 2)
	{
		ft_fdprintf(2, "Num args Error\n Try: %s name_map.ber\n", argv[0]);
		return (-1);
	}
	check_arg_ber(argv[1]);
	read_map(argv[1], &map);
	generate_map(argv[1], &map);
	print_complete_map(map);
	c_map = copy_map(map);
	print_complete_map(c_map);
	free_map_array(&map);
	free_map_array(&c_map);
	return (0);
}
