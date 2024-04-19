/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:25:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/04 17:59:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft/libft.h"

int	ft_nbrlen_base(unsigned int nbr, size_t baselen)
{
	unsigned int	counter;

	counter = 0;
	while (nbr)
	{
		counter++;
		nbr /= baselen;
	}
	return (counter);
}

int	ft_putnbr_base(unsigned int nbr, char *base, size_t baselen)
{
	if (nbr >= baselen)
	{
		if (ft_putnbr_base(nbr / baselen, base, baselen) < 0)
			return (-1);
		if (ft_putnbr_base(nbr % baselen, base, baselen) < 0)
			return (-1);
	}
	else
	{
		if (ft_putchar(base[nbr]) < 0)
			return (-1);
	}
	return (1);
}

int	ft_base(unsigned int nbr, char *base)
{
	size_t	baselen;

	if (!base)
		return (0);
	if (nbr == 0)
		return (ft_putchar('0'));
	baselen = ft_strlen(base);
	if (ft_putnbr_base(nbr, base, baselen) < 0)
		return (-1);
	return (ft_nbrlen_base(nbr, baselen));
}
