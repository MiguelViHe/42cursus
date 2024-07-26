/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/26 16:56:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx42_data(void *param)
{
	t_data	*data;
	
	data = (t_data *)param;
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	mlx_close_window(data->mlx);
	if (data->map)
		free_map_array(data->map);
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
}

void	verify_map_size(t_data *data)
{
	if (data->map->width * 64 > data->screen_width
		|| data->map->height * 64 > data->screen_height)
	{
		ft_fdprintf(2, "Error\n Map is bigger than screen resolution.\n");
		free_mlx42_data(data);
		exit(EXIT_FAILURE);
	}
}

void	hook(void* param)
{
	t_data* data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		free_mlx42_data(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_P))
		mlx_delete_image(data->mlx, data->img);
	for (unsigned int x = 0; x < data->img->width; x++)
		for(unsigned int y = 0; y < data->img->height; y++)
			mlx_put_pixel(data->img, x, y, rand() % RAND_MAX);
}

int	initialize_game(t_map *map)
{
	t_data	data;
	
	ft_memset(&data, 0, sizeof(t_data));
	if (!(data.mlx = mlx_init(map->width * 64, map->height * 64, "mvidal-h", true)))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		free_map_array(data.map);
		return (EXIT_FAILURE);
	}
	data.map = map;
	mlx_get_monitor_size(0, &data.screen_width, &data.screen_height);
	ft_printf("width screen = %d\n",data.screen_width);
	ft_printf("height screen = %d\n",data.screen_height);
	verify_map_size(&data);
	data.img = mlx_new_image(data.mlx, (data.map->width * 64) - 4, (data.map->height * 64) - 4);
	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 2, 2) < 0))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		free_mlx42_data(&data);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_close_hook(data.mlx, free_mlx42_data, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}