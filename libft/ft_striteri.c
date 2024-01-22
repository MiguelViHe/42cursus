/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:39:07 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/22 19:39:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

//sum the intex to the char
static void	enigma(unsigned int index, char *c)
{
	*c = *c + index;
}
//make the encoding method ROT13 to the even elements
static void rot13(unsigned int index, char *c)
{
	if (!(index % 2))
	{
	*c = (*c + 13) % 127;
	if (*c < 32)
		*c += 32;
	}
}*/

/*Apply the function 'f' to each characters of the string 's',
passing its index as a first parameter.
The difference between ft_striteri and ft_strmapi is that ft_striteri
doesn't return anything and works directly on the original string.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
char	str1[] = "world";
char	str2[] = "world";

printf("original1 = %s\n", str1);
printf("original2 = %s\n", str2);
ft_striteri(str1, enigma);
printf("enigma = %s\n", str1);
ft_striteri(str2, rot13);
printf("rot13 = %s\n", str2);
return (0);
}*/
