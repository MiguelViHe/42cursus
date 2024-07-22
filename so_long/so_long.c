/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:03:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/21 17:39:25 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	c_map = copy_map(map);
	if (check_path(&c_map))
	{
		ft_printf("Map is playable.\n");
		initialize_game();
	}
	free_map_array(&map);
	free_map_array(&c_map);
	return (0);
}
