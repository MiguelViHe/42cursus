/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:22:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/03 12:08:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int32_t	center_img_x(t_data *d, mlx_image_t* img)
{
	return ((d->mlx->width / 2) - (img->width / 2));
}

static int32_t	center_img_y(t_data *d, mlx_image_t* img)
{
	return ((d->mlx->height / 2) - (img->height / 2));
}


void	you_win(t_data *d)
{
	free_mlx42_images_array(d, d->img.player);
	ft_printf("YOU WIN! - movements = %d\n", d->map->moves);
	d->img.winner = mlx_put_string(d->mlx, "YOU WIN!", 0, 0);
	mlx_set_instance_depth(&(d->img.winner->instances[0]), 4);
	d->img.winner->instances[0].x += center_img_x(d, d->img.winner);
	d->img.winner->instances[0].y += center_img_y(d, d->img.winner);
}

void	check_win(t_data *d)
{
	if (d->img.exit_c->instances[0].enabled)
	{
		ft_printf("Exit is closed. Take all the collectibles first!\n");
	}
	else if (d->img.exit_o->instances[0].enabled)
	{
		d->map->is_win = 1;
	}
}