/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:07:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 17:09:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define IMG_SIZ 64

//libft
# include "libft/libft.h"

//close, read
# include <unistd.h>

//malloc, free, exit, rand
# include <stdlib.h>

//perror
# include <stdio.h>

//strerror
# include <string.h>

//mlx_t
# include <MLX42/MLX42.h>

//time
# include <time.h>

typedef struct s_map_elems
{
	int	empty;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
	int	enemy;
}				t_map_elems;

typedef struct s_map
{
	int				width;
	int				height;
	int				start_r;
	int				start_c;
	int				exit_r;
	int				exit_c;
	int				is_win_loose;
	unsigned int	moves;
	char			**map;
	t_map_elems		elems;
}				t_map;

typedef struct s_img
{
	mlx_image_t	*empty;
	char		*empty_path;
	mlx_image_t	*wall;
	char		*wall_path;
	mlx_image_t	*collect;
	char		*collect_path;
	mlx_image_t	*exit_o;
	char		*exit_o_path;
	mlx_image_t	*exit_c;
	char		*exit_c_path;
	mlx_image_t	*player[4];
	char		*player_path[4];
	mlx_image_t	*enemy[4];
	char		*enemy_path[4];
	mlx_image_t	*win_loose;
	mlx_image_t	*score;

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
void			print_complete_map(t_map map);

//map_errors.c
void			wrong_map_exit(char *buffer, char *message, int free);
void			check_arg_ber(char *name);
void			wrong_generate_map_exit(char *message, int fd);
void			wrong_copy_map_exit(char **copy_array, int pos);

//check_map.c
void			read_map(char *map_name, t_map *map);
int				get_len_of_line(char *buffer);

//check_map_elems.c
void			check_map_elems(char *map_name, t_map *map);

//files.c
int				secure_open(char *map_name);
void			secure_close(int fd);

//generate_map.c
void			generate_map(char *map_name, t_map *map);

//copy_map.c
t_map			copy_map(t_map map);

//check_path.c
int				check_path(t_map *map);

//game.c
int				initialize_game(t_map *map);

//freeing.c
void			free_map_array(t_map *map);
void			free_mlx42_data(t_data *data);
void			free_mlx42_images_array(t_data *d, mlx_image_t	**img);

//put_images.c
void			images_to_map(t_data *d);

//put_images_elem.c
void			put_inst_empty(t_data *d, int i, int j);
void			put_inst_collectible(t_data *d, int i, int j);
void			put_inst_exit(t_data *d, int i, int j);
void			put_inst_player(t_data *d, int i, int j);
void			put_inst_enemies(t_data *d, int i, int j);

//load_images.c
mlx_image_t		*generate_image(t_data *data, char *path);
void			load_images(t_data *data);

//instances_image.c
mlx_instance_t	*find_instance(mlx_image_t *img, mlx_instance_t player);

//hooks.c
void			on_destroy(void *param);
void			on_keypress(mlx_key_data_t keydata, void *param);

//movements.c
void			move_player(t_data *d, int dir, char *mov);

//actions_in_game.c
void			open_door(t_data *d);
void			take_collectible(t_data *d, int p);

//win.c
void			check_win(t_data *d);
void			you_win_loose(t_data *d, int end_game);

//score.c
void			put_score(t_data *d, char *mov);

//enemies.c
void			move_enemies(t_data *d, mlx_image_t **enemies);

#endif