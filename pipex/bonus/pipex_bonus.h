/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:55:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/03 16:19:41 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END		0
# define WRITE_END		1

//libft
# include "libft/libft.h"

//close, read, fork, pipe, dup2
# include <unistd.h>

//malloc, free, exit, rand
# include <stdlib.h>

//perror
# include <stdio.h>

//strerror
# include <string.h>

//wait
# include <sys/wait.h>

typedef struct s_px_args
{
	int		argc;
	char	**argv;
	char	**env;
	char	**split_env;
	int		num_cmd;
}				t_px_args;

//pipex_utils.c
char	*find_cmd_in_path(char **split_path, const char *cmd);
char	**get_path_env(char *env[]);
t_px_args	args_init(int argc, char *argv[], char *env[]);
void	free_path(char **path_array);
int		secure_open(char *file_name, int in_out);

//ft_split_awk.c
char	**ft_split_awk(char const *s, char c);

//printing.c
void	print_array(char *array[]);
void	print_args(int argc, char *argv[], char *env[]);

#endif
