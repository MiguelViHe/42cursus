/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:31:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/27 14:32:33 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions_utils.h"

/*Return an int number converted fron de string str given.Accepts spaces
and check sign. It stops converting when find a non-digit value.*/
long	ft_atol(const char *str)
{
	long	number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

/*int	main(void)
{
	const char	str[] = "     		\t    \r \v \f  \n   -98738i8372";
	int			num = atoi(str);
	int			num2 = ft_atoi(str);

	printf("El número convertido por original es: %d\n", num);
	printf("El número convertido por ft es: %d\n", num2);
	return (0);
}*/
