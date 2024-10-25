/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:55:31 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/05 11:01:11 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../libft.h" //enlazar ft_strlcpy.Si no crear en utils

int	ft_ptrlen_hexa(unsigned long long nbr)
{
	size_t			baselen;
	unsigned int	counter;

	baselen = 16;
	counter = 2;
	while (nbr)
	{
		counter++;
		nbr /= baselen;
	}
	return (counter);
}

int	ft_putptr_hexa(int fd, unsigned long long nbr)
{
	char	base[17];
	size_t	baselen;

	baselen = 16;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (nbr >= baselen)
	{
		ft_putptr_hexa(fd, nbr / baselen);
		ft_putptr_hexa(fd, nbr % baselen);
	}
	else
	{
		if (ft_putchar(fd, base[nbr]) < 0)
			return (-1);
	}
	return (1);
}

int	ft_putptr(int fd, unsigned long long nbr)
{
	if (nbr == 0)
	{
		if (ft_putstr(fd, "(nil)") < 0)
			return (-1);
		else
			return (5);
	}
	else
	{
		if (ft_putstr(fd, "0x") < 0)
			return (-1);
		if (ft_putptr_hexa(fd, nbr) < 0)
			return (-1);
		return (ft_ptrlen_hexa(nbr));
	}
}
