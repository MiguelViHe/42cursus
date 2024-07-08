/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:23 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/08 19:43:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Write the error message in the stderr, free buffer if necessary and exit*/
void	wrong_map_exit(char *buffer, char *message, int need_free)
{
	ft_fdprintf(2, "%s\n", message);
	if (need_free)
		free(buffer);
	exit(EXIT_FAILURE);
}

/*Check if the map file extension is ".ber". Error and exit if not*/
void	check_arg_ber(char *name)
{
	int	len_total;
	int	len_name;

	len_total = ft_strlen(name);
	len_name = len_total - 4;
	if (!(len_total > 4 && ft_strncmp(name + len_name, ".ber", 4) == 0))
	{
		ft_fdprintf(2, "Error\nWrong map extension.\n");
		exit(EXIT_FAILURE);
	}	
}