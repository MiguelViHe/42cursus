/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:39:00 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_child(int fdp[], char *argv[], char **split_path)
{
	int fd;

	print_array(split_path);
	fd = secure_open(argv[4], 1);
	dup2(fdp[READ_END], STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execlp("/usr/bin/awk", "awk", "{print $3}", NULL);
}

void	first_child(int fdp[], char *argv[], char **split_path)
{
	int	fd;
	
	close(fdp[READ_END]);
	print_array(split_path);
	fd = secure_open(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdp[WRITE_END], STDOUT_FILENO);
	close(fdp[WRITE_END]);
	execlp("/usr/bin/cat", "cat", NULL);
}

void	second_fork(int fdp[], char *argv[], char **split_path)
{
	pid_t	pid;

	close(fdp[WRITE_END]);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		second_child(fdp, argv, split_path);
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
		first_child(fdp, argv, split_path);
	else if (pid > 0) //Padre
		second_fork(fdp, argv, split_path);
	free_path(split_path);
	pid = wait(&status);
	pid = wait(&status);
	return (0);
}
