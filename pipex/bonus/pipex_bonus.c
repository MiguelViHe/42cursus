/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:02:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/04 18:43:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_command(char **split_arg, char *env[], char *path)
{
	if (path)
	{
		if (access(path, X_OK) == 0)
		{
			execve(path, split_arg, env);
			perror("Pipex - execve failed.");
		}
		else
			perror("Pipex - Command not accessible.");
	}
	else
		perror("Pipex - Command not found.");
	free(path);
	free_path(split_arg);
	exit (-1);
}

void	middle_child(t_px_args *args, int fdp[2][2])
{
	char	**split_argv;
	char	*final_path;
	char	*curr_cmd;
	int		next_pipe;
	int		prev_pipe;

	curr_cmd = args->argv[args->num_cmd];
	prev_pipe = ((args->num_cmd) + 1) % 2;
	next_pipe = (args->num_cmd) % 2;
	close(fdp[next_pipe][READ_END]);
	if (!ft_strnstr(curr_cmd, "'", ft_strlen(curr_cmd)))
		split_argv = ft_split(curr_cmd, ' ');
	else
		split_argv = ft_split_squotes(curr_cmd, ' ');
	ft_printf("middle:\n");
	print_array(split_argv);
	final_path = find_cmd_in_path(args->split_path, split_argv[0]);
	free_path(args->split_path);
	dup2(fdp[prev_pipe][READ_END], STDIN_FILENO);
	close(fdp[prev_pipe][READ_END]);
	dup2(fdp[next_pipe][WRITE_END], STDOUT_FILENO);
	close(fdp[next_pipe][READ_END]);
	exec_command(split_argv, args->env, final_path);
}

void	last_child(t_px_args *args, int fdp[2])
{
	int		fd;
	char	**split_argv;
	char	*final_path;
	char	*last_cmd;

	last_cmd = args->argv[(args->argc) - 2];
	fd = secure_open(args->argv[(args->argc) - 1], 1, args);
	if (!ft_strnstr(last_cmd, "'", ft_strlen(last_cmd)))
		split_argv = ft_split(last_cmd, ' ');
	else
		split_argv = ft_split_squotes(last_cmd, ' ');
	ft_printf("last:\n");
	print_array(split_argv);
	final_path = find_cmd_in_path(args->split_path, split_argv[0]);
	free_path(args->split_path);
	dup2(fdp[READ_END], STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec_command(split_argv, args->env, final_path);
}

void	first_child(t_px_args *args, int fdp[2])
{
	int		fd;
	char	**split_argv;
	char	*final_path;

	close(fdp[READ_END]);
	fd = secure_open(args->argv[1], 0, args);
	if (!ft_strnstr(args->argv[2], "'", ft_strlen(args->argv[2])))
		split_argv = ft_split(args->argv[2], ' ');
	else
		split_argv = ft_split_squotes(args->argv[2], ' ');
	ft_printf("first:\n");
	print_array(split_argv);
	final_path = find_cmd_in_path(args->split_path, split_argv[0]);
	free_path(args->split_path);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdp[WRITE_END], STDOUT_FILENO);
	close(fdp[WRITE_END]);
	exec_command(split_argv, args->env, final_path);
}

void childs_management(t_px_args *args, int fdp[2][2], int pid)
{
	if (pid == -1)
		exit(-1);
	else if (pid == 0)
	{
		if (args->num_cmd == 2)
			first_child(args, fdp[0]);
		else if (args->num_cmd == args->argc - 2)

			last_child(args , fdp[((args->num_cmd) + 1) % 2]);
		else
			middle_child(args, fdp);
	}
	else if (pid > 0)
	{
		if (args->num_cmd == 2)
			close(fdp[(args->num_cmd) % 2][WRITE_END]);
		else if (args->num_cmd == args->argc - 2)
			close(fdp[((args->num_cmd) + 1) % 2][READ_END]);
		else
		{
			close(fdp[(args->num_cmd) % 2][WRITE_END]);
			close(fdp[((args->num_cmd) + 1) % 2][READ_END]);
		}
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_px_args	args;
	int			fdp[2][2];
	int			status;
	pid_t		pid;
	
	if (argc < 5)
	{
		ft_fdprintf(2, "Try './pipex infile cmd_1 ... cmd_n outfile'");
		exit (-1);
	}
	args = (args_init(argc, argv, env));
	while (args.num_cmd < argc - 1)
	{
		if (args.num_cmd < argc - 2)
			if (pipe(fdp[args.num_cmd % 2]) == -1)
				exit(-1);
		pid = fork();
		childs_management(&args, fdp, pid);
		args.num_cmd++;
	}
	free_path(args.split_path);
	pid = wait(&status);
	pid = wait(&status);
	return (0);
}

//./pipex infile.txt "cut -d ' ' -f 2,1" "sed 's/[aeiou]/_/g'" "sort" "uniq" "tr 'a-z' 'A-Z'"  outfile.txt
//./pipex infile.txt "awk '{print \$2, \$1}'" "grep o" "awk '{print \$1}'" "grep es" outfile.txt