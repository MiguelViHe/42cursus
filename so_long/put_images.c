/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:04:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/02 15:44:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		mlx_image_to_window(d->mlx, d->img.player[0], j * IMG_SIZE, i * IMG_SIZE);
		d->img.player[0]->instances[(d->img.player[0]->count) - 1].z = 2;
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
	d->img.score = mlx_put_string(d->mlx, "Score: 0", 0, 0);
}
