/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:30:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/17 13:30:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*Return a substring of the strings, starting in index start,
with maximun length len, reserving memory with malloc.
Controlled possible errors:
	-if s doesn't exist return NULL
	-if start is bigger than s length return void string.
	-if memory allocation fails return NULL
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		sub = (char *)malloc((slen - start + 1) * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len > 0)
	{
		sub[i] = s[start];
		start++;
		len--;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*int	main(void)
{
	char			cadena[] = "Hola_Mundo";
	char			*substring;
	unsigned int	start = 8;
	size_t			length = 3;

	substring = ft_substr(cadena, start, length);
	printf("substring = %s\n", substring);
	free(substring);
	return (0);
}*/
