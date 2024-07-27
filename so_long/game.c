/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/27 17:45:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx42_images(t_data *data)
{
	if (data->img.empty)
		mlx_delete_image(data->mlx, data->img.empty);
	if (data->img.wall)
		mlx_delete_image(data->mlx, data->img.wall);
	if (data->img.collectible)
		mlx_delete_image(data->mlx, data->img.collectible);
	if (data->img.exit)
		mlx_delete_image(data->mlx, data->img.exit);
	if (data->img.player)
		mlx_delete_image(data->mlx, data->img.player);
}

void	free_mlx42_data(void *param)
{
	t_data	*data;
	
	data = (t_data *)param;
	free_mlx42_images(data);
	mlx_close_window(data->mlx);
	if (data->map)
		free_map_array(data->map);
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
}

void	verify_map_size(t_data *data)
{
	if (data->map->width * IMG_SIZE > data->screen_width
		|| data->map->height * IMG_SIZE > data->screen_height)
	{
		ft_fdprintf(2, "Error\n Map is bigger than screen resolution.\n");
		free_mlx42_data(data);
		exit(EXIT_FAILURE);
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

mlx_image_t	*generate_image(t_data *data, char *path)
{
	xpm_t		*xpm;
	mlx_image_t	*img;
	
	if (!(xpm = mlx_load_xpm42(path)))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		free_mlx42_data(data);
	}
	if (!(img = mlx_texture_to_image(data->mlx, &xpm->texture)))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		free_mlx42_data(data);
	}
	mlx_delete_xpm42(xpm);
	return (img);
}	

void	load_images(t_data *data)
{
	data->img.empty = generate_image(data, "textures/xpm42/empty.xpm42");
	data->img.wall = generate_image(data, "textures/xpm42/wall.xpm42");
	data->img.collectible = generate_image(data, "textures/xpm42/collectible.xpm42");
	data->img.exit = generate_image(data, "textures/xpm42/exit_open.xpm42");
	data->img.player = generate_image(data, "textures/xpm42/kid_front.xpm42");
}

void	images_to_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map->map[i])
	{
		j = 0;
		while (d->map->map[i][j] && d->map->map[i][j] != '\n')
		{
			if (d->map->map[i][j] == '0')
				mlx_image_to_window(d->mlx, d->img.empty, j * IMG_SIZE, i * IMG_SIZE);
			if (d->map->map[i][j] == '1')
				mlx_image_to_window(d->mlx, d->img.wall, j * IMG_SIZE, i * IMG_SIZE);
			if (d->map->map[i][j] == 'C')
				mlx_image_to_window(d->mlx, d->img.collectible, j * IMG_SIZE, i * IMG_SIZE);
			if (d->map->map[i][j] == 'E')
				mlx_image_to_window(d->mlx, d->img.exit, j * IMG_SIZE, i * IMG_SIZE);
			if (d->map->map[i][j] == 'P')
				mlx_image_to_window(d->mlx, d->img.player, j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
}

int	initialize_game(t_map *map)
{
	t_data	data;
	
	ft_memset(&data, 0, sizeof(t_data));
	if (!(data.mlx = mlx_init(map->width * IMG_SIZE, map->height * IMG_SIZE, "mvidal-h", true)))
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
	ft_printf("llego aqui\n");
	load_images(&data);
	ft_printf("llego aqui2\n");
	images_to_map(&data);
	//mlx_loop_hook(data.mlx, &hook, &data);
	mlx_close_hook(data.mlx, free_mlx42_data, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}