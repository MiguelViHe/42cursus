/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:01:09 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/28 18:22:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_destroy(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_mlx42_data(data);
}

void on_keypress(mlx_key_data_t keydata, void* param)
{
	t_data *data;

	data = (t_data *)param;
	if(data)
	// If we PRESS the 'UP' or 'W' key.
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			&& keydata.action == MLX_PRESS)
		ft_printf("Arriba\n");

	// If we PRESS the 'DOWN' or 'S' key.
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			&& keydata.action == MLX_PRESS)
		ft_printf("Abajo\n");

	// If we PRESS the 'RIGHT' or 'D' key.
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			&& keydata.action == MLX_PRESS)
		ft_printf("Derecha\n");

	// If we PRESS the 'LEFT' or 'S' key.
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			&& keydata.action == MLX_PRESS)
		ft_printf("Izquierda\n");
}
