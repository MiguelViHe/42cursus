/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/04 13:47:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Open file_name in mode input or output depending of the value of in_out.
// If error it free the array of path (split_path) to avoid leaks of memory.
int	secure_open(char *file_name, int in_out, char **split_path)
{
	int	fd;

	if (in_out == 0)
		fd = open(file_name, O_RDONLY);
	else if (in_out == 1)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Pipex - Error opening file");
		free_path(split_path);
		exit (-1);
	}
	return (fd);
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
	pid_t	pid;
	char	**split_path;

	if (argc != 5)
	{
		ft_fdprintf(2, ERROR_ARGUMENT);
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
	return (wait_for_children(2));
}
//./pipex infile.txt "cut -d ' ' -f 2,1" "sed 's/[aeiou]/_/g'"  outfile.txt
//./pipex infisle.txt "awk '{print \$2, \$1}'" "awk '{print \$1}'" outfile.txt