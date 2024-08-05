/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 20:19:03 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*return a int number between 0 and 3 both included.
int	ft_random(void)
{
	double	number;
	int		random;

	number = mlx_get_time();
	random = (int)(number * 10000);
	return (random % 5);
}*/

void	facing_enemy(mlx_image_t **en, int r, int c, size_t num_e)
{
	int	i;
	int	img_n;

	i = 0;
	if (r == 1)
		img_n = 0;
	else if (r == -1)
		img_n = 1;
	else if (c == 1)
		img_n = 2;
	else if (c == -1)
		img_n = 3;
	while (i < 4)
	{
		en[i]->instances[num_e].y += IMG_SIZ * r;
		en[i]->instances[num_e].x += IMG_SIZ * c;
		if (i == img_n)
			en[i]->instances[num_e].enabled = true;
		else
			en[i]->instances[num_e].enabled = false;
		i++;
	}
}

void	change_pos_enemy(t_data *d, int r, int c, size_t num_e)
{
	int		cur_r;
	int		cur_c;

	cur_r = ((d->img.enemy[0]->instances[num_e].y) / IMG_SIZ);
	cur_c = ((d->img.enemy[0]->instances[num_e].x) / IMG_SIZ);
	d->map->map[cur_r][cur_c] = '0';
	if (d->map->map[cur_r + r][cur_c + c] == 'P')
		d->map->is_win_loose = -1;
	d->map->map[cur_r + r][cur_c + c] = 'X';
	facing_enemy(d->img.enemy, r, c, num_e);
}

bool	new_pos_enemy(t_data *d, int r, int c, size_t num_enemy)
{
	char	elem;
	int		cur_r;
	int		cur_c;

	cur_r = ((d->img.enemy[0]->instances[num_enemy].y) / IMG_SIZ);
	cur_c = ((d->img.enemy[0]->instances[num_enemy].x) / IMG_SIZ);
	elem = d->map->map[cur_r + r][cur_c + c];
	if ((elem == '0' || elem == 'P') && !(d->map->is_win_loose))
	{
		change_pos_enemy(d, r, c, num_enemy);
		if (d->map->is_win_loose == -1)
			you_win_loose(d, d->map->is_win_loose);
		return (true);
	}
	return (false);
}

void	move_enemies(t_data *d, mlx_image_t **enemies)
{
	size_t	num_enemy;
	int		dir;
	bool	move;

	num_enemy = 0;
	while (num_enemy < enemies[0]->count && d->map->is_win_loose == 0)
	{
		move = false;
		while (!move)
		{
			dir = rand() % 5;
			if (dir == 0)
				move = new_pos_enemy(d, 1, 0, num_enemy);
			else if (dir == 1)
				move = new_pos_enemy(d, -1, 0, num_enemy);
			else if (dir == 2)
				move = new_pos_enemy(d, 0, 1, num_enemy);
			else if (dir == 3)
				move = new_pos_enemy(d, 0, -1, num_enemy);
			else if (dir == 4)
				move = true;
		}
		num_enemy++;
	}
}
