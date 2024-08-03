/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_loose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:22:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/03 15:42:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int32_t	center_img_x(t_data *d, mlx_image_t *img)
{
	return ((d->mlx->width / 2) - (img->width / 2));
}

static int32_t	center_img_y(t_data *d, mlx_image_t *img)
{
	return ((d->mlx->height / 2) - (img->height / 2));
}

void	you_win_loose(t_data *d, int end_game)
{
	char	*str;

	if (end_game == 1)
	{
		str = "YOU WIN!";
		free_mlx42_images_array(d, d->img.player);
	}
	else if (end_game == -1)
		str = "YOU LOOSE!";
	ft_printf("%s - movements = %d\n", str, d->map->moves);
	d->img.win_loose = mlx_put_string(d->mlx, str, 0, 0);
	mlx_set_instance_depth(&(d->img.win_loose->instances[0]), 4);
	d->img.win_loose->instances[0].x += center_img_x(d, d->img.win_loose);
	d->img.win_loose->instances[0].y += center_img_y(d, d->img.win_loose);
}

void	check_win(t_data *d)
{
	if (d->img.exit_c->instances[0].enabled)
	{
		ft_printf("Exit is closed. Take all the collectibles first!\n");
	}
	else if (d->img.exit_o->instances[0].enabled)
	{
		d->map->is_win_loose = 1;
	}
}
