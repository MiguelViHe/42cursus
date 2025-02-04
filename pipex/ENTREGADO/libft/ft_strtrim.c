/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:14:31 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/18 17:14:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static char	*ft_ptrtrim(char const *s1, char const *set)
{
	char	*end;
	int		i;

	end = (char *)s1 + ft_strlen(s1) - 1;
	i = 0;
	while (set[i])
	{
		if (*end == set[i])
		{
			end--;
			i = 0;
		}
		else
			i++;
	}
	return (end);
}

static char	*ft_ptltrim(char const *s1, char const *set)
{
	char	*first;
	int		i;

	first = (char *)s1;
	i = 0;
	while (set[i])
	{
		if (*first == set[i])
		{
			first++;
			i = 0;
		}
		else
			i++;
	}
	return (first);
}

/*Allocate (with malloc) and returns a copy of s1, without the characters
specified in set at the beginning and the end of s1.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptrtrim;
	char	*ptltrim;
	char	*clean;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	ptltrim = ft_ptltrim(s1, set);
	if (*ptltrim == '\0')
		return (ft_strdup(""));
	ptrtrim = ft_ptrtrim(s1, set);
	len = ptrtrim - ptltrim + 1;
	clean = (char *)malloc((len + 1) * sizeof(char));
	if (!clean)
		return (NULL);
	ft_strlcpy(clean, ptltrim, len + 1);
	return (clean);
}

/*int	main(void)
{
		//char	*clean = NULL;
	char	clean[] = "3321Hola1112";
	char	set[] = "123";
	char	*result;

	result = ft_strtrim(clean, set);
	printf("cleaned string = %s\n", result);
	free(result);
	return (0);
}*/
