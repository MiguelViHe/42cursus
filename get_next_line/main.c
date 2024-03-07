/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:52:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/07 20:03:59 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*result;
	int		i;

	i = 12;
	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}
	while (i)
	{
		result = get_next_line(fd);
		if (result == NULL)
			break ;
		printf("%s\n", result);
		free (result);
		i--;
	}
	close (fd);
	return (0);
}
