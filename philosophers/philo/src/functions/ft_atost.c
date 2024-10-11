/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:42:29 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/11 16:01:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions_utils.h"
#include <unistd.h> //size_t

/*Return an size_t number converted fron de string str given.Accepts spaces
but not negative sign. It stops converting when find a non-digit value.*/
size_t	ft_atost(const char *str)
{
	size_t	number;
	int		i;

	number = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}
