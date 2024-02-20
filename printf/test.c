/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:21 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/20 17:18:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //para probar original.
#include <limits.h> //para probar los limites.

int	main(void)
{
	int		result;
	char	*ptr = "pepe";
	char	*ptr2 = "miguel";

	result = ft_printf("(FT)int: %d, %i %% str: %s\n", INT_MIN, INT_MAX, "OK");
	printf("(OR)int: %d, %i %% str: %s\n", INT_MIN, INT_MAX, "OK");
	ft_printf("Caracteres = %d\n", result);
	result = ft_printf("(FT)%u %X %x %% %d, %i\n", -11, -15, 23233, -365, -23);
	printf("(OR)%u %X %x %% %d, %i\n", -11, -15, 23233, -365, -23);
	ft_printf("Caracteres = %d\n", result);
	result = ft_printf("(FT)direccion ptr es %p, contenido %s\n", &ptr, ptr);
	printf("(OR)direccion ptr es %p, contenido %s\n", &ptr, ptr);
	ft_printf("Caracteres = %d\n", result);
	result = ft_printf("(FT)direccion ptr2 es %p, contenido %s\n", &ptr2, ptr2);
	printf("(OR)direccion ptr2 es %p, contenido %s\n", &ptr2, ptr2);
	ft_printf("Caracteres = %d\n", result);
	return (0);
}
