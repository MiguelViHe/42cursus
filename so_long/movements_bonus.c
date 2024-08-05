/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:19:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 20:20:12 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	facing_player(t_data *d, int r, int c, int img_n)
{
	int			i;
	int			j;
	mlx_image_t	**img;

	i = d->map->start_r;
	j = d->map->start_c;
	img = d->img.player;
	if (img[img_n])
	{
		img[img_n]->instances[0].y += IMG_SIZ * r;
		img[img_n]->instances[0].x += IMG_SIZ * c;
	}
	else
	{
		free_mlx42_images_array(d, img);
		img[img_n] = generate_image(d, d->img.player_path[img_n]);
		mlx_image_to_window(d->mlx, img[img_n], j * IMG_SIZ, i * IMG_SIZ);
		img[img_n]->instances[(img[img_n]->count) - 1].z = 2;
	}
	return (img_n);
}

static int	change_pos_player(t_data *d, int r, int c)
{
	if (d->map->start_r == d->map->exit_r && d->map->start_c == d->map->exit_c)
		d->map->map[d->map->start_r][d->map->start_c] = 'E';
	else
		d->map->map[d->map->start_r][d->map->start_c] = '0';
	d->map->start_r += r;
	d->map->start_c += c;
	d->map->map[d->map->start_r][d->map->start_c] = 'P';
	d->map->moves++;
	if (r == 1)
		return (facing_player(d, r, c, 0));
	else if (r == -1)
		return (facing_player(d, r, c, 1));
	else if (c == 1)
		return (facing_player(d, r, c, 2));
	else if (c == -1)
		return (facing_player(d, r, c, 3));
	return (-1);
}

static void	new_pos_player(t_data *d, int r, int c, char *mov)
{
	char			elem;
	int				p;

	elem = d->map->map[d->map->start_r + r][d->map->start_c + c];
	if ((elem == '0' || elem == 'C' || elem == 'E' || elem == 'X')
		&& !(d->map->is_win_loose))
	{
		p = change_pos_player(d, r, c);
		if (elem == 'C')
			take_collectible(d, p);
		else if (elem == 'E')
			check_win(d);
		else if (elem == 'X')
			d->map->is_win_loose = -1;
		put_score(d, mov);
		if (d->map->is_win_loose != 0)
			you_win_loose(d, d->map->is_win_loose);
		if (d->map->elems.enemy != 0)
			move_enemies(d, d->img.enemy);
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
