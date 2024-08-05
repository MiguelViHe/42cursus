/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 20:19:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	verify_map_size(t_data *data)
{
	if (data->map->width * IMG_SIZ > data->screen_width
		|| data->map->height * IMG_SIZ > data->screen_height)
	{
		ft_fdprintf(2, "Error\n Map is bigger than screen resolution.\n");
		free_mlx42_data(data);
	}
}

int	initialize_game(t_map *map)
{
	t_data	data;
	int		width;
	int		height;

	ft_memset(&data, 0, sizeof(t_data));
	width = map->width * IMG_SIZ;
	height = map->height * IMG_SIZ;
	data.mlx = mlx_init(width, height, "mvidal-h", false);
	if (!data.mlx)
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		free_map_array(data.map);
		return (EXIT_FAILURE);
	}
	data.map = map;
	mlx_get_monitor_size(0, &data.screen_width, &data.screen_height);
	ft_printf("width screen = %d\n", data.screen_width);
	ft_printf("height screen = %d\n", data.screen_height);
	verify_map_size(&data);
	load_images(&data);
	images_to_map(&data);
	mlx_key_hook(data.mlx, on_keypress, &data);
	mlx_close_hook(data.mlx, on_destroy, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
