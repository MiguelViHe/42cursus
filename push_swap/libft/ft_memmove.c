/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/16 18:08:54 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*It is used to copy a block of memory from one location to another,
 even if there is overlap between the source and destination areas.*/
void	*ft_memmove(void *dst, const void *src, size_t len)
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
		if (str_dest > str_src)
		{
			while (len-- > 0)
				str_dest[len] = str_src[len];
		}
		else
		{
			while (i++ < len)
				str_dest[i - 1] = str_src[i - 1];
		}
	}
	return (dst);
}

/*int main() {
    char origen[] = "Hola, mundo!";
    char origen2[] = "Hola, mundo!";
    char *destino = origen + 4;
    char *destino2 = origen2 + 4;

    //src < dest
    memmove(destino, origen, 6);
    printf("OrigenO: %s\nDestinoO: %s\n", origen, destino);
    ft_memmove(destino2, origen2, 6);
    printf("Origen: %s\nDestino: %s\n", origen2, destino2);
    //src > dest
    memmove(origen, destino, 6);
    printf("OrigenO: %s\nDestinoO: %s\n", destino, origen);
    ft_memmove(origen2, destino2, 6);
    printf("Origen: %s\nDestino: %s\n", destino2, origen2);
    return 0;
}*/
