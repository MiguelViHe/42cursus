/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:45:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/10 16:36:11 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "pipex_bonus.h"

t_px_args	args_init(int argc, char *argv[], char *env[])
{
	t_px_args	args;

	args.argc = argc;
	args.argv = argv;
	args.env = env;
	args.split_path = get_path_env(env);
	if (!ft_strnstr(argv[1], "here_doc", ft_strlen(argv[1])))
		args.num_cmd = 2;
	else
		args.num_cmd = 3;
	args.first_cmd = args.num_cmd;
	return (args);
}

int	secure_open_bonus(char *file_name, int in_out, t_px_args *args)
{
	int	fd;

	if (in_out == 0)
		fd = open(file_name, O_RDONLY);
	else if (in_out == 1)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (in_out == 2)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("Pipex - Error opening file");
		free_path(args->split_path);
		exit (-1);
	}
	return (fd);
}
