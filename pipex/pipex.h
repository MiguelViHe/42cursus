/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:55:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/27 16:59:23 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
char    **get_path_env(char *env[]);

#endif
