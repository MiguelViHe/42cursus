/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:55:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/30 14:59:19 by mvidal-h         ###   ########.fr       */
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

//pipex_utils.c
char	**get_path_env(char *env[]);
void	free_path(char **path_array);
int		secure_open(char *file_name, int in_out);
char	*find_cmd_in_path(char **split_path, const char *cmd);

//ft_split_awk.c
char	**ft_split_awk(char const *s, char c);

//printing.c
void	print_array(char *array[]);
void	print_args(int argc, char *argv[], char *env[]);

#endif
