/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:05:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/16 18:27:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
//para las funciones en test
//#include <string.h>

// Copy a memory block from src to dst. n is the number of bytes to be copied.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str_dest;
	const unsigned char	*str_src;

	if (!dst && !src)
		return (NULL);
	if (dst != src)
	{
		str_dest = dst;
		str_src = src;
		i = 0;
		while (i < n)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	}
	return (dst);
}

/*int main() {
    char origen[] = "Hola, mundo!";
    char destino[20];
    char origen2[] = "Hola, mundo!";
    char destino2[20];
    //char *origen = NULL;
    //char *destino = NULL;
    //char *origen2 = NULL;
    //char *destino2 = NULL;

    memcpy(destino, origen, 7);
    printf("OrigenO: %s\nDestinoO: %s\n", origen, destino);
    ft_memcpy(destino2, origen2, 7);
    printf("Origen: %s\nDestino: %s\n", origen2, destino2);
    return 0;
}*/
