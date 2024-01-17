/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:08:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/16 16:25:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*Compare the first n characters of two character strings.
Returns an integer value less than, equal to, or greater than zero,
depending on whether string1 is less than, equal to, or greater than string2.*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0') && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d\n", strncmp(argv[1], argv[2], 4));
		printf("%d\n", ft_strncmp(argv[1], argv[2], 4));
	}
	else
		printf("El numero de parametros debe ser 3");
}*/
