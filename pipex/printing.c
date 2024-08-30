/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:34:32 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:35:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
