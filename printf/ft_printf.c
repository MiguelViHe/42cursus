/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:47:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/29 18:02:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
%c Imprime un solo carácter.
%s Imprime una string (como se define por defecto en C).
%p El puntero void * dado como argumento se imprime en formato hexadecimal.
%d Imprime un número decimal (base 10).
%i Imprime un entero en base 10.
%u Imprime un número decimal (base 10) sin signo.
%x Imprime un número hexadecimal (base 16) en minúsculas.
%X Imprime un número hexadecimal (base 16) en mayúsculas.
%% para imprimir el símbolo del porcentaje.
*/

int	ft_putoption(char option, va_list args)
{
	if (option == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (option == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (option == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	else if (option == 'd' || option == 'i')
		return (ft_digit(va_arg(args, int)));
	else if (option == 'u')
		return (ft_base(va_arg(args, unsigned int), "0123456789"));
	else if (option == 'x')
		return (ft_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (option == 'X')
		return (ft_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (option == '%')
		return (ft_putchar(option));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int			i;
	int			counter;
	va_list		args;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			counter += ft_putchar(str[i]);
		else
		{
			i++;
			counter += ft_putoption(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (counter);
}
