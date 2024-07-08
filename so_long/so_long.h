/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:07:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/08 12:14:46 by mvidal-h         ###   ########.fr       */
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

typedef struct	s_map_elems
{
	int	empty;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
}				t_map_elems;

typedef struct	s_map
{
	int				width;
	int				height;
	int				start_x;
	int				start_y;
	int				exit_x;
	int				exit_y;
	unsigned int	moves;
	char			**map;
	t_map_elems		*chars;
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

//parse.c
void	read_map(char *map_name);

#endif