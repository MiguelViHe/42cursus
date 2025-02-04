/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:39:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/04 18:36:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../libft.h"

/*size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	i;

	counter = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (counter);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}*/

int	ft_putchar(int fd, char c)
{
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(fd, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(fd, &str[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}
