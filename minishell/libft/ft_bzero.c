/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:39:21 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/16 17:59:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

// Fill with zero the first n bytes of the memory block pointed by ptr.
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	str[20] = "Hola mundo";
	int		i;

	i = 0;
	bzero(str, 3);
	while (i < 20)
	{
		printf("%c ", str[i]);
		i++;
	}
	ft_bzero(str, 5);
	i = 0;
	while (i < 20)
	{
		printf("%c ", str[i]);
		i++;
	}
	return (0);
}*/
