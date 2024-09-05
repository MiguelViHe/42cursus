/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:55:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/05 12:06:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

typedef struct s_px_args
{
	int		argc;
	int		num_cmd;
	char	**argv;
	char	**env;
	char	**split_path;
}				t_px_args;

//pipex_utils_bonus.c
t_px_args	args_init(int argc, char *argv[], char *env[]);
int			secure_open_bonus(char *file_name, int in_out, t_px_args *args);

#endif
