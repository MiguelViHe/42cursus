/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:19:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/29 15:56:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	new_pos_player(t_data *d, int r, int c, char *mov)
{
	if (d->map->map[d->map->start_r + r][d->map->start_c + c] != '1')
	{
		d->map->start_r += r;
		d->map->start_c += c;
		d->map->moves++;
		d->img.player->instances[0].y += IMG_SIZE * r;
		d->img.player->instances[0].x += IMG_SIZE * c;
		ft_printf("%s, movs = %d\n", mov, d->map->moves);
	}
}

void	move_player(t_data *d, int dir, char *mov)
{
	if (dir == MLX_KEY_UP || dir == MLX_KEY_W)
		new_pos_player(d, -1, 0, mov);
	if (dir == MLX_KEY_DOWN || dir == MLX_KEY_S)
		new_pos_player(d, 1, 0, mov);
	if (dir == MLX_KEY_RIGHT || dir == MLX_KEY_D)
		new_pos_player(d, 0, 1, mov);
	if (dir == MLX_KEY_LEFT || dir == MLX_KEY_A)
		new_pos_player(d, 0, -1, mov);
}