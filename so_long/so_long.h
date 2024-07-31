/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:07:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/31 12:36:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define IMG_SIZE 32

#ifndef SO_LONG_H
# define SO_LONG_H

//libft
# include "libft/libft.h"

//close, read
# include <unistd.h>

//malloc, free, exit
# include <stdlib.h>

//perror
# include <stdio.h>

//strerror
# include <string.h>

//mlx_t
# include <MLX42/MLX42.h>

typedef struct s_map_elems
{
	int	empty;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
}				t_map_elems;

typedef struct s_map
{
	int				width;
	int				height;
	int				start_r;
	int				start_c;
	int				exit_r;
	int				exit_c;
	int				is_win;
	unsigned int	moves;
	char			**map;
	t_map_elems		elems;
}				t_map;

typedef struct s_img
{
	mlx_image_t	*empty;
	mlx_image_t	*wall;
	mlx_image_t	*collect;
	mlx_image_t	*exit_o;
	mlx_image_t *exit_c;
	mlx_image_t	*player;
}	t_img;


typedef struct s_data
{
	mlx_t		*mlx;
	int32_t		screen_width;
	int32_t		screen_height;
	t_img		img;
	t_map		*map;
}	t_data;

//printing.c
void	print_complete_map(t_map map);

//map_errors.c
void	wrong_map_exit(char *buffer, char *message, int free);
void	check_arg_ber(char *name);
void	wrong_generate_map_exit(char *message, int fd);
void	wrong_copy_map_exit(char **copy_array, int pos);

//check_map.c
void	read_map(char *map_name, t_map *map);
int		get_len_of_line(char *buffer);

//check_map_elems.c
void	check_map_elems(char *map_name, t_map *map);

//files.c
int		secure_open(char *map_name);
void	secure_close(int fd);

//generate_map.c
void	generate_map(char *map_name, t_map *map);

//copy_map.c
t_map	copy_map(t_map map);

//check_path.c
int		check_path(t_map *map);

//game.c
int		initialize_game();

//freeing.c
void	free_map_array(t_map *map);
void	free_mlx42_data(t_data *data);

//game_images.c
void	load_images(t_data *data);
void	images_to_map(t_data *d);

//hooks.c
void	on_destroy(void *param);
void on_keypress(mlx_key_data_t keydata, void* param);

//movements.c
void	move_player(t_data *d, int dir, char *mov);


#endif