/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/29 16:50:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END		0
#define WRITE_END		1

void	print_array(char *array[])
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("Array pos %d: %s\n", i, array[i]);
		i++;
	}
}

void	print_args(int argc, char *argv[], char *env[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_printf("Argumento %d: %s\n", i, argv[i]);
		i++;
	}
	i = 0;
	while (env[i])
	{
		ft_printf("Env %d: %s\n", i, env[i]);
		i++;
	}
}

void	second_child(int fdp[], char *argv[], char **split_path)
{
	int fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
	fd = open(argv[1], O_RDONLY);
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
