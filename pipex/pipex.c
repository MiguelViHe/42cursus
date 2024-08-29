/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/29 11:06:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END	0
#define WRITE_END	1
#define FILE_NAME	"infile"

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

void	second_child(int fdp[])
{
	int fd;

	fd = open(FILE_NAME, O_WRONLY);
	dup2(fdp[READ_END], STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execlp("/usr/bin/cat", "cat", NULL);
}

void	first_child(int fdp[])
{
	close(fdp[READ_END]);
	dup2(fdp[WRITE_END], STDOUT_FILENO);
	close(fdp[WRITE_END]);
	execlp("/bin/ls", "ls", "-l", NULL);
}

void	second_fork(int fdp[])
{
	pid_t	pid;

	close(fdp[WRITE_END]);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		second_child(fdp);
	else if (pid > 0)
		close(fdp[READ_END]);
}

int main(int argc, char *argv[], char *env[])
{
	int 	fdp[2];
	int		status;
	pid_t	pid;
	char	**path_array;
	char	**awk;

	path_array = get_path_env(env);
	free_path(path_array);
	awk = ft_split_awk("    awk -F',' '{print $1, $2, $3}'   ", ' ');
	print_array(awk);
	free_path(awk);
	if (argc != 5)
	{
		ft_fdprintf(2, "Bad num args. Try './pipex infile cmd1 cmd2 outfile'");
		exit (-1);
	}
	print_args(argc, argv, env); //Luego quitar
	if (pipe(fdp) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0) //hijo
		first_child(fdp);
	else if (pid > 0) //Padre
		second_fork(fdp);
	pid = wait(&status);
	pid = wait(&status);
	return (0);
}
