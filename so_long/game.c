/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/03 11:56:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_map_size(t_data *data)
{
	if (data->map->width * IMG_SIZE > data->screen_width
		|| data->map->height * IMG_SIZE > data->screen_height)
	{
		ft_fdprintf(2, "Error\n Map is bigger than screen resolution.\n");
		free_mlx42_data(data);
	}
}

/*void	hook(void* param)
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
}*/

int	initialize_game(t_map *map)
{
	t_data	data;
	int		width;
	int		height;
	
	ft_memset(&data, 0, sizeof(t_data));
	width = map->width * IMG_SIZE;
	height = map->height * IMG_SIZE;
	if (!(data.mlx = mlx_init(width, height, "mvidal-h", false)))
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
	load_images(&data);
	images_to_map(&data);
	//mlx_loop_hook(data.mlx, &hook, &data);
	mlx_key_hook(data.mlx, on_keypress, &data);
	mlx_close_hook(data.mlx, on_destroy, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}