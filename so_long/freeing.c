/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/31 19:28:36 by mvidal-h         ###   ########.fr       */
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
	if (data->img.exit_o)
		mlx_delete_image(data->mlx, data->img.exit_o);
	if (data->img.exit_c)
		mlx_delete_image(data->mlx, data->img.exit_c);
	if (data->img.player)
		mlx_delete_image(data->mlx, data->img.player);
	if (data->img.player)
		mlx_delete_image(data->mlx, data->img.winner);
	if (data->img.player)
		mlx_delete_image(data->mlx, data->img.score);
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