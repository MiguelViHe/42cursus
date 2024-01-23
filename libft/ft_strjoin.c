/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:47:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/17 23:47:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*Allocate (with malloc) and returns a new string resulting from
the concatenation of s1 and s2.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	cadena1[] = "hola, ";
	char	cadena2[] = "como estas?";
	char	*resultado;

	resultado = ft_strjoin(cadena1, cadena2);
	printf("resultado = %s\n", resultado);
	free(resultado);
	return (0);
}*/
