/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:43:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/14 18:43:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*locates the first occurence of the null-terminated string needle in the
string haystack, where not more than len characters are searched.
If needle is an empty string, haystack is returned,
if needle occurs nowhere in haystack, NULL is returned,
otherwise a pointer to the first character of the first occurence of needle
is returned.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > len)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "perone";
	char	needle[] = "ron";
	char	*result;

	result = ft_strnstr(str, needle, 50);
	if (!result)
		printf("No se ha encontrado coincidencia\n");
	else
		printf("%s\n", result);
	return (0);
}*/
