/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:09:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/02 16:44:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 500, 500);
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_loop(mlx);
	
}

