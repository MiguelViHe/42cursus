/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:23 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/04 17:56:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg_ber(char *name)
{
	int	len_total;
	int	len_name;

	len_total = ft_strlen(name);
	len_name = len_total - 4;
	if (!(len_total > 4 && ft_strncmp(name + len_name, ".ber", 4) == 0))
	{
		perror("Error\nWrong map extension");
		exit(-1);
	}	
}