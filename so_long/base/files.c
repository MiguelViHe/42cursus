/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:53:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/05 19:59:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	secure_open(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_fdprintf(2, "Error opening file.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	secure_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_fdprintf(2, "Error closing file.\n");
		exit(EXIT_FAILURE);
	}
}
