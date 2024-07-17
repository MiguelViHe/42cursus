/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:07:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/17 10:50:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	unsigned int	moves;
	char			**map;
	t_map_elems		*elems;
}				t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			screen_width;
	int			screen_height;
	//t_img		*img;
	t_map		*map;
}	t_data;

//map_errors.c
void	wrong_map_exit(char *buffer, char *message, int free);
void	check_arg_ber(char *name);
void	wrong_generate_map_exit(char *message, int fd);

//check_map.c
void	read_map(char *map_name, t_map *map);
int		get_len_of_line(char *buffer);

//check_map_elems.c
void	check_map_elems(char *map_name, t_map *map);

//files.c
int		secure_open(char *map_name);
void	secure_close(int fd);

//generate_map.c
void 	generate_map(char *map_name, t_map *map);
void	free_map_array(t_map *map);

#endif