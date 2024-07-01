/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:03:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 13:45:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

int	ft_biggest(int num1, int num2)
{
	if (num1 >= num2)
		return (num1);
	else
		return (num2);
}

/*Return an int number converted fron de string str given.Accepts spaces
and check sign. It stops converting when find a non-digit value.
Also stop if the number is bigger than MAX_INT*/
long	str_to_int(const char *str)
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
		if (!is_limits_integer(number * sign))
			return (number * sign);
		i++;
	}
	return (number * sign);
}
