/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:39:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/14 12:39:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
//#include <string.h>

/*The memcmp() function compares byte string s1 against byte string s2.
Both strings are assumed to be n bytes long.
Returns zero if the two strings are identical, otherwise returns the difference
between the first two differing bytes*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	if (n == 0)
		return (0);
	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (ptr1[i] == ptr2[i] && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}

/*n-1 because i start at 0 and when it enters the last time in the loop,
I add one extra to test the last one when we leave the while loop.*/
/*int	main(void)
{
	//Con array de char.
	const char str[] = "Hola Mundo!";
	const char str2[] = "Hola Mundo!";

	//printf("original = %d\n", memcmp(str, str2, sizeof(str)));
	//printf("ft = %d\n", ft_memcmp(str, str2, sizeof(str)));
	printf("original = %d\n", memcmp(str, str2, 0));
	printf("ft = %d\n", ft_memcmp(str, str2, 0));
}

	//con array de ints
	int array[] = {1, 2, 3, 4, 19, 6, 15, 18};
	int array2[] = {1, 2, 3, 4, 22, 6, 7, 18};

	size_t tamano = sizeof(array) / sizeof(array[0]);
	//printf("tamano = sizeof(array) / sizeof(array[0]) ->
	 %d = %d / %d\n", tamano, sizeof(array), sizeof(array[0]));
	int resultadoO = memcmp(array, array2, tamano * sizeof(int));
	int resultadoft = ft_memcmp(array, array2, tamano * sizeof(int));

	if (resultadoO > 0)
		printf("o array es mayor que array2: %d\n", resultadoO);
	else if (resultadoO < 0)
		printf("o array es menor que array2: %d\n", resultadoO);
	else
		printf("o array y array2 son iguales\n");

	if (resultadoft > 0)
		printf("o array es mayor que array2: %d\n", resultadoft);
	else if (resultadoft < 0)
		printf("o array es menor que array2: %d\n", resultadoft);
	else
		printf("o array y array2 son iguales\n");
}*/
