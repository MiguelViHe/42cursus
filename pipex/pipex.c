/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/02 16:44:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(char **split_argv, char *env[], char *path)
{
	if (path)
	{
		if (access(path, X_OK) == 0)
		{
			execve(path, split_argv, env);
			perror("Pipex - execve failed");
			exit (-1);
		}
		else
		{
			perror("Pipex - Command not accessible");
			exit (-2);
		}
	}
	else
	{
		perror("Pipex - Command not found");
		exit (-3);
	}
}

void	second_child(char *argv[], char *env[], int fdp[], char **split_env)
{
	int		fd;
	char	**split_argv;
	char	*final_path;

	fd = secure_open(argv[4], 1);
	if (!ft_strnstr(argv[3], "awk", ft_strlen(argv[3])))
		split_argv = ft_split(argv[3], ' ');
	else
		split_argv = ft_split_awk(argv[3], ' ');
	final_path = find_cmd_in_path(split_env, split_argv[0]);
	free_path(split_env);
	dup2(fdp[READ_END], STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec_command(split_argv, env, final_path);
}

void	first_child(char *argv[], char *env[], int fdp[], char **split_env)
{
	int		fd;
	char	**split_argv;
	char	*final_path;

	close(fdp[READ_END]);
	fd = secure_open(argv[1], 0);
	if (!ft_strnstr(argv[2], "awk", ft_strlen(argv[2])))
		split_argv = ft_split(argv[2], ' ');
	else
		split_argv = ft_split_awk(argv[2], ' ');
	final_path = find_cmd_in_path(split_env, split_argv[0]);
	free_path(split_env);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdp[WRITE_END], STDOUT_FILENO);
	close(fdp[WRITE_END]);
	exec_command(split_argv, env, final_path);
}

void	second_fork(char *argv[], char *env[], int fdp[], char **split_env)
{
	pid_t	pid;

	close(fdp[WRITE_END]);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		second_child(argv, env, fdp, split_env);
	else if (pid > 0)
		close(fdp[READ_END]);
}

int	main(int argc, char *argv[], char *env[])
{
	int		fdp[2];
	int		status;
	pid_t	pid;
	char	**split_env;

	if (argc != 5)
	{
		ft_fdprintf(2, "Bad num args. Try './pipex infile cmd1 cmd2 outfile'");
		exit (-1);
	}
	split_env = get_path_env(env);
	if (pipe(fdp) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		first_child(argv, env, fdp, split_env);
	else if (pid > 0)
		second_fork(argv, env, fdp, split_env);
	free_path(split_env);
	pid = wait(&status);
	pid = wait(&status);
	return (0);
}
