/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/04 17:36:47 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//return a int number between 0 and 3 both included.
int	ft_random(void)
{
	double	number;
	int		random;

	number = mlx_get_time();
	random = (int)(number * 10000);
	return (random % 5);
}

void	facing_enemy(mlx_image_t **en, int r, int c, int img_n, size_t num_e)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		en[i]->instances[num_e].y += IMG_SIZE * r;
		en[i]->instances[num_e].x += IMG_SIZE * c;
		if (i == img_n)
			en[i]->instances[num_e].enabled = true;
		else
			en[i]->instances[num_e].enabled = false;
		i++;
	}
}

void	change_pos_enemy(t_data *d, int cur_r, int cur_c, int r, int c, size_t num_e)
{
	d->map->map[cur_r][cur_c] = '0';
	if (d->map->map[cur_r + r][cur_c + c] == 'P')
		d->map->is_win_loose = -1;
	d->map->map[cur_r + r][cur_c + c] = 'X';
	if (r == 1)
		facing_enemy(d->img.enemy, r, c, 0, num_e);
	else if (r == -1)
		facing_enemy(d->img.enemy, r, c, 1, num_e);
	else if (c == 1)
		facing_enemy(d->img.enemy, r, c, 2, num_e);
	else if (c == -1)
		facing_enemy(d->img.enemy, r, c, 3, num_e);
}

bool	new_pos_enemy(t_data *d, int r, int c, size_t num_enemy)
{
	char	elem;
	int		cur_r;
	int		cur_c;

	cur_r = ((d->img.enemy[0]->instances[num_enemy].y) / IMG_SIZE);
	cur_c = ((d->img.enemy[0]->instances[num_enemy].x) / IMG_SIZE);
	ft_printf("cur_r es: %d y r es: %d\n", cur_r, r);
	ft_printf("cur_c es: %d y c es: %d\n", cur_c, c);
	elem = d->map->map[cur_r + r][cur_c + c];
	ft_printf("Elem es: %c\n", elem);
	if ((elem == '0' || elem == 'P') && !(d->map->is_win_loose))
	{
		change_pos_enemy(d, cur_r, cur_c, r, c, num_enemy);
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
		dir = ft_random();
		while (!move)
		{
			if (dir == 0)
				if (!(move = new_pos_enemy(d, 1, 0, num_enemy)))
					dir += 1;
			if (dir == 1)
				if (!(move = new_pos_enemy(d, -1, 0, num_enemy)))
					dir += 1;
			if (dir == 2)
				if (!(move = new_pos_enemy(d, 0, 1, num_enemy)))
					dir += 1;
			if (dir == 3)
				if (!(move = new_pos_enemy(d, 0, -1, num_enemy)))
					dir += 1;
			if (dir == 4)
				move = true;
		}
		num_enemy++;
	}
}
