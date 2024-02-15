/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:01:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/15 20:41:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int nbr)
{
	int		counter;
	long	aux;

	aux = nbr;
	counter = 0;
	if (nbr <= 0)
	{
		counter++;
		aux = -aux;
	}
	while (aux)
	{
		counter++;
		aux /= 10;
	}
	return (counter);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putstr("-2");
			nbr = 147483648;
		}
		else
		{
			ft_putchar('-');
			nbr = -nbr;
		}
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	ft_digit(int nbr)
{
	ft_putnbr(nbr);
	return (ft_nbrlen(nbr));
}
