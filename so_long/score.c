/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:32:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/01 12:08:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_score(t_data *d)
{
	char *moves;
	char *cat_score;

	moves = ft_itoa(d->map->moves);
	cat_score = (char *)ft_calloc(8 + ft_strlen(moves), sizeof(char));
	ft_strlcat(cat_score, "Score: ", 8);
	ft_strlcat(cat_score, moves, 8 + ft_strlen(moves));
	if (d->img.score)
		mlx_delete_image(d->mlx, d->img.score);
	d->img.score = mlx_put_string(d->mlx, cat_score, 0, 0);
	mlx_set_instance_depth(&(d->img.score->instances[0]), 3);
	free(moves);
	free(cat_score);
}