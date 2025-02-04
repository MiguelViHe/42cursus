/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:28:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/04 13:19:32 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*The strlcat function attempts to concatenate the source string (src) to the
 destination string (dest) without exceeding the specified buffer size (size).
  It returns the total length (dest + src) despite not all src was concatenated
   or size + src length if dest content is largest than size*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	if (!src || !*src)
		return (0);
	src_length = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (dstsize + src_length);
	dest_length = ft_strlen(dst);
	if (dstsize == 0 || dstsize < dest_length)
		return (dstsize + src_length);
	j = 0;
	while (src[j] != '\0' && (dest_length + j < dstsize - 1))
	{
		dst[dest_length + j] = src[j];
		j++;
	}
	dst[dest_length + j] = '\0';
	return (dest_length + src_length);
}

/*int	main(void)
{
	char	desti[12] = "qwerty";
	char	src[] = "QWER";
	size_t	length;
	//size_t	original;

	length = ft_strlcat(desti, src, 7);
	//original = strlcat(desti, src, 12);
	printf("longitud = %d, destino = %s\n", length, desti);
	//printf("longituds = %d, destinos = %s\n", original, desti);
}*/
