/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:55:31 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/25 13:44:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h" //enlazar ft_strlcpy.Si no crear en utils

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

void	ft_putptr_hexa(unsigned long long nbr)
{
	char	base[17];
	size_t	baselen;

	baselen = 16;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (nbr >= baselen)
	{
		ft_putptr_hexa(nbr / baselen);
		ft_putptr_hexa(nbr % baselen);
	}
	else
		ft_putchar(base[nbr]);
}

int	ft_putptr(unsigned long long nbr)
{
	ft_putstr("0x");
	if (nbr == 0)
		return (ft_putchar('0' + 2));
	ft_putptr_hexa(nbr);
	return (ft_ptrlen_hexa(nbr));
}
