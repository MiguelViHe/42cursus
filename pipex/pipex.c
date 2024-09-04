/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/04 18:41:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	second_child(char *argv[], char *env[], int fdp[], char **split_path)
{
	int		fd;
	char	**split_argv;
	char	*final_path;

	fd = secure_open(argv[4], 1, split_path);
	if (!ft_strnstr(argv[3], "'", ft_strlen(argv[3])))
		split_argv = ft_split(argv[3], ' ');
	else
		split_argv = ft_split_squotes(argv[3], ' ');
	final_path = find_cmd_in_path(split_path, split_argv[0]);
	free_path(split_path);
	dup2(fdp[READ_END], STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec_command(split_argv, env, final_path);
}

void	first_child(char *argv[], char *env[], int fdp[], char **split_path)
{
	int		fd;
	char	**split_argv;
	char	*final_path;

	close(fdp[READ_END]);
	fd = secure_open(argv[1], 0, split_path);
	if (!ft_strnstr(argv[2], "'", ft_strlen(argv[2])))
		split_argv = ft_split(argv[2], ' ');
	else
		split_argv = ft_split_squotes(argv[2], ' ');
	final_path = find_cmd_in_path(split_path, split_argv[0]);
	free_path(split_path);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdp[WRITE_END], STDOUT_FILENO);
	close(fdp[WRITE_END]);
	exec_command(split_argv, env, final_path);
}

void	second_fork(char *argv[], char *env[], int fdp[], char **split_path)
{
	pid_t	pid;

	close(fdp[WRITE_END]);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		second_child(argv, env, fdp, split_path);
	else if (pid > 0)
		close(fdp[READ_END]);
}

int	main(int argc, char *argv[], char *env[])
{
	int		fdp[2];
	int		status;
	pid_t	pid;
	char	**split_path;

	if (argc != 5)
	{
		ft_fdprintf(2, "Bad num args. Try './pipex infile cmd1 cmd2 outfile'");
		exit (-1);
	}
	split_path = get_path_env(env);
	if (pipe(fdp) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		first_child(argv, env, fdp, split_path);
	else if (pid > 0)
		second_fork(argv, env, fdp, split_path);
	free_path(split_path);
	pid = wait(&status);
	pid = wait(&status);
	return (0);
}
//./pipex infile.txt "cut -d ' ' -f 2,1" "sed 's/[aeiou]/_/g'"  outfile.txt
//./pipex infisle.txt "awk '{print \$2, \$1}'" "awk '{print \$1}'" outfile.txt