/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:44:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/04 13:18:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

//Return the length of the string given as a parameter.
size_t	ft_strlen(const char *s)
{
	size_t	counter;

	if (!s || !*s)
		return (0);
	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

/*int	main(void)
{
	printf("length = %lu\n", ft_strlen("Camion"));
	printf("lengthO = %lu\n", strlen("Camion"));
	printf("length = %lu\n", ft_strlen(""));
	printf("lengthO = %lu\n", strlen(""));
	return (0);
}*/
