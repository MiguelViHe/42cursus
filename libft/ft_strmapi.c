/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:28:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/22 14:28:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*
//sum the intex to the char
static char	enigma(unsigned int index, char c)
{
	return (c + index);
}
//make the encoding method ROT13 to the even elements
static char	rot13(unsigned int index, char c)
{
	if (!(index % 2))
	{
	c = (c + 13) % 126;
	if (c < 32)
		c += 32;
	}
	return (c);
}*/

/*Apply the function 'f' to each characters in the string 's' to create a
new string (with malloc) resulting of the successive applications of 'f'.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main(void)
{
char	str[] = "Hello world";

printf("original = %s\n", str);
printf("enigma = %s\n", ft_strmapi(str, enigma));
printf("rot13 = %s\n", ft_strmapi(str, rot13));
return (0);
}*/
