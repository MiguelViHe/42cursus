/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/16 17:58:20 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*Copy the value character (unsigned char)
into the first num bytes of the memory block pointed by b).*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*int	main(void)
{
	char	str[20] = "Hola mundo";

	memset(str, '$', 5); // memset da warning si usamos 0 como 3er parametro.
	printf("Cadena resultante: %s\n", str);
	ft_memset(str, '*', 3);
	printf("Cadena resultante: %s\n", str);
	return (0);
}*/
