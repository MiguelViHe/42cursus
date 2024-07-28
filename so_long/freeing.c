/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/28 13:07:59 by mvidal-h         ###   ########.fr       */
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

void	free_mlx42_images(t_data *data)
{
	if (data->img.empty)
		mlx_delete_image(data->mlx, data->img.empty);
	if (data->img.wall)
		mlx_delete_image(data->mlx, data->img.wall);
	if (data->img.collect)
		mlx_delete_image(data->mlx, data->img.collect);
	if (data->img.exit)
		mlx_delete_image(data->mlx, data->img.exit);
	if (data->img.player)
		mlx_delete_image(data->mlx, data->img.player);
}

void	free_mlx42_data(t_data *data)
{
	free_mlx42_images(data);
	mlx_close_window(data->mlx);
	if (data->map)
		free_map_array(data->map);
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
}