/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:45:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/27 17:03:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_path_env(char *env[])
{
	int		i;
	char	*path;
	char	**path_array;

	i = 0;
	path = NULL;
	if(!env)
		return (NULL);
	while (!path && env[i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		i++;
	}
	path += 5;
	path_array = ft_split(path, ':');
	i = 0;
	while (path_array[i])
	{
		ft_printf("path = %s\n", path_array[i]);
		i++;
	}
	return (path_array);
}