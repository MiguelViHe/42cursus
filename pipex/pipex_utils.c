/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:45:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/05 11:37:15 by mvidal-h         ###   ########.fr       */
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

char	*find_cmd_in_path(char **split_path, const char *cmd)
{
	int		i;
	char	*path;
	size_t	len;

	i = 0;
	path = NULL;
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	if (split_path)
	{
		while (split_path[i])
		{
			len = (ft_strlen(split_path[i]) + ft_strlen(cmd) + 2);
			path = (char *)ft_calloc(len, sizeof(char));
			if (path == NULL)
				exit(1);
			ft_strlcat(path, split_path[i++], len);
			ft_strlcat(path, "/", len);
			ft_strlcat(path, cmd, len);
			if (access(path, F_OK) == 0)
				return (path);
			free(path);
		}
	}
	return (NULL);
}

char	**get_path_env(char *env[])
{
	int		i;
	char	*path;
	char	**path_array;

	i = 0;
	path = NULL;
	if (!env)
		return (NULL);
	while (!path && env[i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		i++;
	}
	if (path)
	{
		path += 5;
		path_array = ft_split(path, ':');
		i = 0;
	}
	return (path_array);
}

void	free_path(char **path_array)
{
	int	i;

	i = 0;
	while (path_array[i])
	{
		free(path_array[i]);
		i++;
	}
	free(path_array);
}

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
