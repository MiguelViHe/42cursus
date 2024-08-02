/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:19:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/02 17:38:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_door(t_data *d)
{
	d->img.exit_c->instances[0].enabled = false;
	d->img.exit_o->instances[0].enabled = true;
}

static int	facing_player(t_data *d, mlx_image_t **img, int r, int c, int img_n)
{
	int	i;
	int	j;

	i = d->map->start_r;
	j = d->map->start_c;
	if (img[img_n])
	{
		img[img_n]->instances[0].y += IMG_SIZE * r;
		img[img_n]->instances[0].x += IMG_SIZE * c;
	}
	else
	{
		free_mlx42_images_array(d, img);
		img[img_n] = generate_image(d, d->img.player_path[img_n]);
		mlx_image_to_window(d->mlx, img[img_n], j * IMG_SIZE, i * IMG_SIZE);
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
		return (facing_player(d, d->img.player, r, c, 0));
	else if (r == -1)
		return (facing_player(d, d->img.player, r, c, 1));
	else if (c == 1)
		return (facing_player(d, d->img.player, r, c, 2));
	else if (c == -1)
		return (facing_player(d, d->img.player, r, c, 3));
	return (-1);
}

static void	new_pos_player(t_data *d, int r, int c, char *mov)
{
	mlx_instance_t	*in;
	char			elem;
	int				p;

	elem = d->map->map[d->map->start_r + r][d->map->start_c + c];
	if ((elem == '0' || elem == 'C' || elem == 'E') && !(d->map->is_win))
	{
		p = change_pos_player(d, r, c);
		if (elem == 'C')
		{
			in = find_instance(d->img.collect, d->img.player[p]->instances[0]);
			in->enabled = false;
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