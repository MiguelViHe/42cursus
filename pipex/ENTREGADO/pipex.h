/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:55:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/04 13:49:02 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END		0
# define WRITE_END		1

# define ERROR_ARGUMENT "Try './pipex infile cmd1 cmd2 outfile'\n"

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
int		wait_for_children(int num_children);
void	exec_command(char **split_arg, char *env[], char *path);
char	*find_cmd_in_path(char **split_path, const char *cmd);
char	**get_path_env(char *env[]);
void	free_path(char **path_array);

//ft_split_squotes.c
char	**ft_split_squotes(char const *s, char c);

//printing.c
void	print_array(char *array[]);
void	print_args(int argc, char *argv[], char *env[]);

#endif
