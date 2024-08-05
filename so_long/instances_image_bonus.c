/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instances_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:46:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 20:19:54 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_instance_t	*find_instance(mlx_image_t *img, mlx_instance_t player)
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
