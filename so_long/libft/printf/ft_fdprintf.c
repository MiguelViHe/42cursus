/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:44:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/04 18:44:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* PERMITE SELECCIONAR EL FILE DESCRIPTOR DONDE ESCRIBIR.
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

int	ft_fdprintf(int fd, char const *str, ...)
{
	int			i;
	int			counter;
	va_list		args;
	int			control;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			control = ft_putchar(fd, str[i]);
		else
			control = ft_putoption(fd, str[++i], args);
		if (control < 0)
			return (control);
		counter += control;
		i++;
	}
	va_end(args);
	return (counter);
}