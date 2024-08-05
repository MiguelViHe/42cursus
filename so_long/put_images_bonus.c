/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:04:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 20:20:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			mlx_image_to_window(d->mlx, d->img.empty, j * IMG_SIZ, i * IMG_SIZ);
			d->img.empty->instances[(d->img.empty->count) - 1].z = 0;
			j++;
		}
		i++;
	}
}

void	put_first_layer(t_data *d, char elem, int i, int j)
{
	if (elem == '1')
		put_inst_empty(d, i, j);
	else if (elem == 'C')
		put_inst_collectible(d, i, j);
	else if (elem == 'E')
		put_inst_exit(d, i, j);
	else if (elem == 'P')
		put_inst_player(d, i, j);
	else if (elem == 'X')
		put_inst_enemies(d, i, j);
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
			if (d->map->map[i][j] == 'X')
				put_first_layer(d, 'X', i, j);
			j++;
		}
		i++;
	}
	d->img.score = mlx_put_string(d->mlx, "Score: 0", 0, 0);
}
