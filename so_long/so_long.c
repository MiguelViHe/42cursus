/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:03:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/04 17:55:49 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		perror("Incorrect number or arguments");
		exit (-1);
	}
	check_arg_ber(argv[1]);
	ft_printf("Arg correcto\n");
	return (0);
}