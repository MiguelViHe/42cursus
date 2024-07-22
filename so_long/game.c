/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/22 09:54:25 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <MLX42/MLX42.h>

int	initialize_game()
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			i;
	int			j;
	
	if (!(mlx = mlx_init(512, 512, "so_long - mvidal-h", true)))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < 255)
	{
		j = 0;
		while (j < 255)
		{
			mlx_put_pixel(img, i, j, 0x000080FF);
			j++;
		}
		mlx_put_pixel(img, i, j, 0xFF0000FF);
		i++;
	}
	j = 0;
	while (j < 256)
	{
		mlx_put_pixel(img, i, j, 0xFF0000FF);
		j++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}