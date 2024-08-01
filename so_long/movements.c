/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:19:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/01 12:11:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_instance_t*	find_instance(mlx_image_t *img, mlx_instance_t player)
{
	size_t	i;
	
	i = 0;
	while (i < img->count)
	{
		if (img->instances[i].x == player.x && img->instances[i].y == player.y)
			return (&(img->instances[i]));
		i++;
	}
	return (NULL);
}

static void	open_door(t_data *d)
{
	d->img.exit_c->instances[0].enabled = false;
	d->img.exit_o->instances[0].enabled = true;
}

static void	change_pos_player(t_data *d, int r, int c)
{
	if (d->map->start_r == d->map->exit_r && d->map->start_c == d->map->exit_c)
		d->map->map[d->map->start_r][d->map->start_c] = 'E';
	else
		d->map->map[d->map->start_r][d->map->start_c] = '0';
	d->map->start_r += r;
	d->map->start_c += c;
	d->map->map[d->map->start_r][d->map->start_c] = 'P';
	d->map->moves++;
	d->img.player->instances[0].y += IMG_SIZE * r;
	d->img.player->instances[0].x += IMG_SIZE * c;
}

static void	new_pos_player(t_data *d, int r, int c, char *mov)
{
	mlx_instance_t	*inst;
	char elem;

	elem = d->map->map[d->map->start_r + r][d->map->start_c + c];
	if ((elem == '0' || elem == 'C' || elem == 'E') && !(d->map->is_win))
	{
		change_pos_player(d, r, c);
		if (elem == 'C')
		{
			inst = find_instance(d->img.collect, d->img.player->instances[0]);
			inst->enabled = false;
			d->map->elems.collectible--;
			if (d->map->elems.collectible == 0)
				open_door(d);
		}
		else if (elem == 'E')
			check_win(d);
		ft_printf("%s, collect = %d\n", mov, d->map->elems.collectible);
		put_score(d);
		if (d->map->is_win)
			you_win(d);
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