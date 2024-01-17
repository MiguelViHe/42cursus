/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:01:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/12 14:01:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*Return the first coincidence of c in the string s
or NULL if it doesn't exist*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (*s != '\0')
		return ((char *)s);
	return (NULL);
}

/*int	main(void)
{
	const char	*cadena = "Hola, mundo";
	char		caracter = 'm';
	char		*resultado = strchr(cadena, caracter);
	char		*resultadoft = ft_strchr(cadena, caracter);

	printf("or = %s\n", resultado);
	printf("ft = %s\n", resultadoft);
	return (0);
}*/
