/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:31:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/20 19:38:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

//Return 1 when c is one of the values defined in isspace.
static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/*Return an int number converted fron de string str given.Accepts spaces
and check sign. It stops converting when find a non-digit value.*/
int	ft_atol(const char *str)
{
	long long int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
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
