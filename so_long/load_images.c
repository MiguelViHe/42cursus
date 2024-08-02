/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:42:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/02 17:59:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*generate_image(t_data *data, char *path)
{
	xpm_t		*xpm;
	mlx_image_t	*img;
	
	if (!(xpm = mlx_load_xpm42(path)))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		free_mlx42_data(data);
	}
	if (!(img = mlx_texture_to_image(data->mlx, &xpm->texture)))
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		mlx_delete_xpm42(xpm);
		free_mlx42_data(data);
	}
	mlx_delete_xpm42(xpm);
	return (img);
}	

void	load_paths(t_data *d)
{
	d->img.empty_path = "textures/xpm42/floor1.xpm42";
	d->img.wall_path = "textures/xpm42/wall.xpm42";
	d->img.collect_path = "textures/xpm42/collect.xpm42";
	d->img.exit_o_path = "textures/xpm42/exit_open.xpm42";
	d->img.exit_c_path = "textures/xpm42/exit_close.xpm42";
	d->img.player_path[0] = "textures/xpm42/player_f.xpm42";
	d->img.player_path[1] = "textures/xpm42/player_b.xpm42";
	d->img.player_path[2] = "textures/xpm42/player_r.xpm42";
	d->img.player_path[3] = "textures/xpm42/player_l.xpm42";
	d->img.enemy_path[0] = "textures/xpm42/enemy_f.xpm42";
	d->img.enemy_path[1] = "textures/xpm42/enemy_b.xpm42";
	d->img.enemy_path[2] = "textures/xpm42/enemy_r.xpm42";
	d->img.enemy_path[3] = "textures/xpm42/enemy_l.xpm42";
}

void	load_images(t_data *d)
{
	load_paths(d);
	d->img.empty = generate_image(d, d->img.empty_path);
	d->img.wall = generate_image(d, d->img.wall_path);
	d->img.collect = generate_image(d, d->img.collect_path);
	d->img.exit_o = generate_image(d, d->img.exit_o_path);
	d->img.exit_c = generate_image(d, d->img.exit_c_path);
	d->img.player[0] = generate_image(d, d->img.player_path[0]);
	d->img.enemy[0] = generate_image(d, d->img.enemy_path[0]);
	d->img.enemy[1] = generate_image(d, d->img.enemy_path[1]);
	d->img.enemy[2] = generate_image(d, d->img.enemy_path[2]);
	d->img.enemy[3] = generate_image(d, d->img.enemy_path[3]);
}
