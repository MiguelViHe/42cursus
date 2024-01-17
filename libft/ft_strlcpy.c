/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:50:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/11 11:50:40 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*The strlcpy function is used to copy strings from source to destination,
t takes the size of the destination buffer as an argument and guarantees that
 the buffer will not overflow.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	i;

	counter = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (counter);
}

/*int	main(void)
{
	char			destino[15];
	unsigned int	longitud;
	char			origen[] = "1234567890123456789";

	longitud = ft_strlcpy(destino, origen, 10);
	printf ("origen = %s\n", origen);
	printf ("destino: %s\n", destino);
	printf ("longitud = %d\n", longitud);
	return (0);
}*/
