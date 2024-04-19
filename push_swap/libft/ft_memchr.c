/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:32:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/13 20:32:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
//#include <string.h>

/*locates the first occurence of c (convered to an unsigned char) in string s.
It works with byte string, in memory*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		usc;

	ptr = s;
	usc = (unsigned char)c;
	while (n > 0 && *ptr != usc)
	{
		ptr++;
		n--;
	}
	if (n == 0)
		return (NULL);
	return ((void *)ptr);
}

/*int	main(void)
{
	//Con array de char.
	const char str[] = "Hola, mundo!";
	char chr = 'u';

	printf("%s\n", (char *)memchr(str, chr, 7));
	printf("%s\n", (char *)ft_memchr(str, chr, 7));

	//con array de ints
	int array[] = {1, 2, 3, 4, 19, 6, 7, 18};
	int valor_buscado = 18;

	size_t tamano = sizeof(array) / sizeof(array[0]);
	//printf("tamano = sizeof(array) / sizeof(array[0])
	 -> %d = %d / %d\n", tamano, sizeof(array), sizeof(array[0]));
	int *resultadoO = memchr(array, valor_buscado, tamano * sizeof(int));
	int *resultadoft = ft_memchr(array, valor_buscado, tamano * sizeof(int));

	if (resultadoO != NULL)
		printf("ovalor %d  en la posición %d.\n",
	 valor_buscado, resultadoO - array);
	else
		printf("ovalor %d no fue encontrado.\n", valor_buscado);

	if (resultadoft != NULL)
		printf("mvalor %d  en la posición %d.\n",
	 valor_buscado, resultadoft - array);
	else
		printf("mvalor %d no fue encontrado.\n", valor_buscado);
	return (0);
}*/
