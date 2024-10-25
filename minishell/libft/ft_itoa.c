/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:36:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/21 19:36:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
//#include <limits.h>

static size_t	count_numbers(long ln)
{
	size_t	counter;

	counter = 0;
	if (ln < 0)
	{
		counter++;
		ln = -ln;
	}
	if (ln == 0)
		counter++;
	while (ln != 0)
	{
		counter++;
		ln /= 10;
	}
	return (counter);
}

static char	*fill_str_number(char *str, size_t n_digits, long ln)
{
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	if (ln == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (ln != 0)
	{
		str[n_digits - 1] = (ln % 10) + '0';
		ln /= 10;
		n_digits--;
	}
	return (str);
}

/*Convert  a number into its representation in string
First count the num of digits of the int adding one for the sign (if it exists)
Second allocate enough memory for the digist +1 to nul-terminate
Third, fill de string allecated with the character of every digit*/
char	*ft_itoa(int n)
{
	size_t	num_digits;
	char	*str;
	long	ln;

	ln = n;
	num_digits = count_numbers(ln);
	str = (char *)ft_calloc(num_digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = fill_str_number(str, num_digits, ln);
	return (str);
}

/*int	main(void)
{
	char	*result;

	result = ft_itoa(-2147483648);
	printf("numero en cadena = %s\n", result);
	printf("El rango de int es: %d a %d\n", INT_MIN, INT_MAX);
    printf("El rango de long int es: %ld a %ld\n", LONG_MIN, LONG_MAX);
	return (0);
}*/
