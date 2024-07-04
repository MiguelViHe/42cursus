/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:09:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/04 16:51:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(void)
{
	void    *mlx;
	void    *mlx_win;
	t_data  img;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("Error initializing MLX\n");
		return (1);
	}
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	if (!mlx_win)
	{
		ft_printf("Error creating window\n");
		return (1);
	}
	img.img = mlx_new_image(mlx, 500, 500);
	if (!img.img)
	{
		ft_printf("Error creating image\n");
		return (1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
	{
		ft_printf("Error getting image address\n");
		return (1);
	}

/* Imprimir información para depuración
    ft_printf("Bits per pixel: %d\n", img.bits_per_pixel);
    ft_printf("Line length: %d\n", img.line_length);
    ft_printf("Endian: %d\n", img.endian);
*/

	// Rellenar toda la imagen con un color específico para pruebas
    for (int y = 0; y < 500; y++)
    {
        for (int x = 0; x < 500; x++)
        {
            my_mlx_pixel_put(&img, x, y, 0x0000FF00); // Verde
			//ft_printf("verde\n");
        }
    }

    // Poner varios pixeles rojos para prueba adicional
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            my_mlx_pixel_put(&img, 10 + i, 10 + j, 0x00FF0000);
			//ft_printf("rojo\n");

        }
    }

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// Manejar eventos
    mlx_hook(mlx_win, 17, 0, close_window, NULL); // Cerrar ventana con el botón de cerrar
    mlx_loop(mlx);
    return (0);
}

