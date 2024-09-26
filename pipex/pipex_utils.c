/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:45:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/26 11:51:23 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Makes father process waiting for the children to ensure that all of them 
//finish correctly and avoid zombies process.
int	wait_for_children(int num_children)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_children)
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			return (-1);
		}
		i++;
	}
	return (0);
}

//Make the execve of the cmd (the complete path of cmd) checking first if
// it is executable or if exist.
// It frees everything if and error happends. 
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

//Checks if command exists. First checks if command exixts in current directory
//If not it checks if command exists in every path of splith_path. It builds
//the path adding "/" and "cmd" to every path of split_path and check if it
// exists. If exists it returns the path.
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

//Finds the line that starts with "PATH=" in env, and, if exists 
//creates and array splitting the line with ":" and returns it.
char	**get_path_env(char *env[])
{
	int		i;
	char	*path;
	char	**path_array;

	i = 0;
	path = NULL;
	path_array = NULL;
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

// Free the array of paths that is split with get_path_env.
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
