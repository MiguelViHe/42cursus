/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:02:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/03 12:20:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_inst_empty(t_data *d, int i, int j)
{
	mlx_image_to_window(d->mlx, d->img.wall, j * IMG_SIZE, i * IMG_SIZE);
	d->img.wall->instances[(d->img.wall->count) - 1].z = 1;
}

void	put_inst_collectible(t_data *d, int i, int j)
{
	mlx_image_to_window(d->mlx, d->img.collect, j * IMG_SIZE, i * IMG_SIZE);
	d->img.collect->instances[(d->img.collect->count - 1)].z = 1;
}

void	put_inst_exit(t_data *d, int i, int j)
{
	mlx_image_to_window(d->mlx, d->img.exit_o, j * IMG_SIZE, i * IMG_SIZE);
	d->img.exit_o->instances[(d->img.exit_o->count - 1)].z = 1;
	d->img.exit_o->instances[(d->img.exit_o->count - 1)].enabled = false;
	mlx_image_to_window(d->mlx, d->img.exit_c, j * IMG_SIZE, i * IMG_SIZE);
	d->img.exit_c->instances[(d->img.exit_c->count - 1)].z = 1;
}

void	put_inst_player(t_data *d, int i, int j)
{
	mlx_image_to_window(d->mlx, d->img.player[0], j * IMG_SIZE, i * IMG_SIZE);
	d->img.player[0]->instances[(d->img.player[0]->count) - 1].z = 2;
}

void	put_inst_enemies(t_data *d, int i, int j)
{
	mlx_image_to_window(d->mlx, d->img.enemy[0], j * IMG_SIZE, i * IMG_SIZE);
	d->img.enemy[0]->instances[(d->img.enemy[0]->count) - 1].z = 3;
	mlx_image_to_window(d->mlx, d->img.enemy[1], j * IMG_SIZE, i * IMG_SIZE);
	d->img.enemy[1]->instances[(d->img.enemy[1]->count) - 1].z = 3;
	d->img.enemy[1]->instances[(d->img.enemy[1]->count) - 1].enabled = false;
	mlx_image_to_window(d->mlx, d->img.enemy[2], j * IMG_SIZE, i * IMG_SIZE);
	d->img.enemy[2]->instances[(d->img.enemy[2]->count) - 1].z = 3;
	d->img.enemy[2]->instances[(d->img.enemy[2]->count) - 1].enabled = false;
	mlx_image_to_window(d->mlx, d->img.enemy[3], j * IMG_SIZE, i * IMG_SIZE);
	d->img.enemy[3]->instances[(d->img.enemy[3]->count) - 1].z = 3;
	d->img.enemy[3]->instances[(d->img.enemy[3]->count) - 1].enabled = false;
}