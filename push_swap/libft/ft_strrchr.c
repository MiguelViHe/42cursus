/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/12 17:53:28 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h> // para el strrchr original
//#include <stdio.h>
#include "libft.h"

/*Return the last coincidence of c in the string s
or NULL if it doesn't exist*/
char	*ft_strrchr(const char *s, int c)
{
	char	*aux;

	aux = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			aux = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (aux);
}

/*int	main(void)
{
	const char	*cadena = "Hola, mundooooo!";
	char		caracter = 'w';
	char		*resultado = strrchr(cadena, caracter + 256);
	char		*resultadoft = ft_strrchr(cadena, caracter + 256);

	printf("or = %s\n", resultado);
	printf("ft = %s\n", resultadoft);
	return (0);
}*/
