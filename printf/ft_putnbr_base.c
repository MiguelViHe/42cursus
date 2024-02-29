/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:25:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/29 17:57:26 by mvidal-h         ###   ########.fr       */
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

void	ft_putnbr_base(unsigned int nbr, char *base, size_t baselen)
{
	if (nbr >= baselen)
	{
		ft_putnbr_base(nbr / baselen, base, baselen);
		ft_putnbr_base(nbr % baselen, base, baselen);
	}
	else
		ft_putchar(base[nbr]);
}

int	ft_base(unsigned int nbr, char *base)
{
	size_t	baselen;

	if (!base)
		return (0);
	if (nbr == 0)
		return (ft_putchar('0'));
	baselen = ft_strlen(base);
	ft_putnbr_base(nbr, base, baselen);
	return (ft_nbrlen_base(nbr, baselen));
}
