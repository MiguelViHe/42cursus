/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:51:32 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/15 20:21:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*result;
	char	*result2;
	char	*result3;

	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	fd2 = open("prueba2.txt", O_RDONLY);
	if (fd2 == -1)
		return (1);
	fd3 = open("prueba3.txt", O_RDONLY);
	if (fd3 == -1)
		return (1);
	while (1)
	{
		result = get_next_line(fd);
		result2 = get_next_line(fd2);
		result3 = get_next_line(fd3);
		if (result == NULL && result2 == NULL && result3 == NULL)
		{
			close (fd);
			close (fd2);
			close (fd3);
			break ;
		}
		if (result)
		{
			printf("fd = %s\n", result);
			free (result);
		}
		if (result2)
		{
			printf("fd2 = %s\n", result2);
			free (result2);
		}
		if (result3)
		{
			printf("fd3 = %s\n", result3);
			free (result3);
		}
	}
	return (0);
}
