/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:55:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/06 13:33:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER_HD_SIZE 1024

typedef struct s_px_args
{
	int		argc;
	int		num_cmd;
	int		first_cmd;
	char	**argv;
	char	**env;
	char	**split_path;
}				t_px_args;

//pipex_utils_bonus.c
t_px_args	args_init(int argc, char *argv[], char *env[]);
int			secure_open_bonus(char *file_name, int in_out, t_px_args *args);

//here_doc.c
int			here_doc(t_px_args *args);

#endif
