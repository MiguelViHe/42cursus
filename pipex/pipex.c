/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/30 16:04:50 by mvidal-h         ###   ########.fr       */
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
			exit (-1);
		}
		else
		{
			perror("Pipex - Command not accessible.");
			exit (-2);
		}
	}
	else
	{
		perror("Pipex - Command not found.");
		exit (-3);
	}
}

void	second_child(char *argv[], char *env[], int fdp[], char **split_path)
{
	int fd;
	(void)env;
	(void)split_path;
	fd = secure_open(argv[4], 1);
	dup2(fdp[READ_END], STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execlp("/usr/bin/awk", "awk", "{print $2}", NULL);
}

void	first_child(char *argv[], char *env[], int fdp[], char **split_path)
{
	int		fd;
	char	**split_arg;
	char	*final_path;
	
	close(fdp[READ_END]);
	if (!ft_strnstr(argv[2], "awk", 3))
		split_arg = ft_split(argv[2], ' ');
	else
		split_arg = ft_split_awk(argv[2], ' ');
	final_path = find_cmd_in_path(split_path, split_arg[0]);
	ft_printf("final_path = %s\n", final_path);
	free_path(split_path);
	fd = secure_open(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdp[WRITE_END], STDOUT_FILENO);
	close(fdp[WRITE_END]);
	exec_command(split_arg, env, final_path);
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

int main(int argc, char *argv[], char *env[])
{
	int 	fdp[2];
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
	if (pid == 0) //hijo
		first_child(argv, env, fdp, split_path);
	else if (pid > 0) //Padre
		second_fork(argv, env, fdp, split_path);
	free_path(split_path);
	pid = wait(&status);
	pid = wait(&status);
	return (0);
}
