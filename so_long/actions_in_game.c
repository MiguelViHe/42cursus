/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_in_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:52:23 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 10:03:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_door(t_data *d)
{
	d->img.exit_c->instances[0].enabled = false;
	d->img.exit_o->instances[0].enabled = true;
}

void	take_collectible(t_data *d, int p)
{
	mlx_instance_t	*inst;

	inst = find_instance(d->img.collect, d->img.player[p]->instances[0]);
	inst->enabled = false;
	d->map->elems.collectible--;
	if (d->map->elems.collectible == 0)
		open_door(d);
}
