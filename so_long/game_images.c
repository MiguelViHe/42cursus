/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:04:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/29 19:31:39 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		mlx_delete_xpm42(xpm);
		free_mlx42_data(data);
	}
	mlx_delete_xpm42(xpm);
	return (img);
}	

void	load_images(t_data *data)
{
	data->img.empty = generate_image(data, "textures/xpm42/empty.xpm42");
	data->img.wall = generate_image(data, "textures/xpm42/wall.xpm42");
	data->img.collect = generate_image(data, "textures/xpm42/collect.xpm42");
	data->img.exit_o = generate_image(data, "textures/xpm42/exit_open.xpm42");
	data->img.exit_c = generate_image(data, "textures/xpm42/exit_close.xpm42");
	data->img.player = generate_image(data, "textures/xpm42/kid_front.xpm42");
}

void	put_base_layer(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map->map[i])
	{
		j = 0;
		while (d->map->map[i][j] && d->map->map[i][j] != '\n')
		{
			mlx_image_to_window(d->mlx, d->img.empty, j * IMG_SIZE, i * IMG_SIZE);
			d->img.empty->instances[(d->img.empty->count) - 1].z = 0;
			j++;
		}
		i++;
	}
}

void	put_first_layer(t_data *d, char elem, int i, int j)
{
	if (elem == '1')
	{
		mlx_image_to_window(d->mlx, d->img.wall, j * IMG_SIZE, i * IMG_SIZE);
		d->img.wall->instances[(d->img.wall->count) - 1].z = 1;
	}
	else if (elem == 'C')
	{
		mlx_image_to_window(d->mlx, d->img.collect, j * IMG_SIZE, i * IMG_SIZE);
		d->img.collect->instances[(d->img.collect->count - 1)].z = 1;
	}
	else if (elem == 'E')
	{
		mlx_image_to_window(d->mlx, d->img.exit_o, j * IMG_SIZE, i * IMG_SIZE);
		d->img.exit_o->instances[(d->img.exit_o->count - 1)].z = 1;
		d->img.exit_o->instances[(d->img.exit_o->count - 1)].enabled = false;
		mlx_image_to_window(d->mlx, d->img.exit_c, j * IMG_SIZE, i * IMG_SIZE);
		d->img.exit_c->instances[(d->img.exit_c->count - 1)].z = 1;
	}
	else if (elem == 'P')
	{
		mlx_image_to_window(d->mlx, d->img.player, j * IMG_SIZE, i * IMG_SIZE);
		d->img.player->instances[(d->img.player->count) - 1].z = 1;
	}
}

void	images_to_map(t_data *d)
{
	int	i;
	int	j;

	put_base_layer(d);
	i = 0;
	while (d->map->map[i])
	{
		j = 0;
		while (d->map->map[i][j] && d->map->map[i][j] != '\n')
		{
			if (d->map->map[i][j] == '1')
				put_first_layer(d, '1', i, j);
			if (d->map->map[i][j] == 'C')
				put_first_layer(d, 'C', i, j);
			if (d->map->map[i][j] == 'E')
				put_first_layer(d, 'E', i, j);
			if (d->map->map[i][j] == 'P')
				put_first_layer(d, 'P', i, j);
			j++;
		}
		i++;
	}
}
