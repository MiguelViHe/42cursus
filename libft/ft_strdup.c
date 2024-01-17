/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:29:32 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/16 19:21:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

/*Allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it.*/
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len);
	return (str);
}

/*int	main(void)
{
	char	src[] = "Hola_mundo!";
	char	*ori;
	char	*ft;

	ori = strdup(src);
	ft = ft_strdup(src);
	printf("src = %s\n", src);
	printf("ori = %s\n", ori);
	printf("ft = %s\n", ft);
	return (0);
}*/
