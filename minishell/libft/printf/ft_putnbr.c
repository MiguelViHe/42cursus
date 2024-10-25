/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:01:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/04 18:39:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../libft.h"

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

int	ft_putnbr(int fd, int nbr)
{
	if (nbr == -2147483648)
	{
		if (ft_putstr(fd, "-2") < 0)
			return (-1);
		nbr = 147483648;
	}
	else if (nbr < 0)
	{
		if (ft_putchar(fd, '-') < 0)
			return (-1);
		nbr = -nbr;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		if (ft_putchar(fd, nbr + '0') < 0)
			return (-1);
	}
	else
	{
		if (ft_putnbr(fd, nbr / 10) < 0)
			return (-1);
		if (ft_putnbr(fd, nbr % 10) < 0)
			return (-1);
	}
	return (1);
}

int	ft_digit(int fd, int nbr)
{
	if (ft_putnbr(fd, nbr) < 0)
		return (-1);
	return (ft_nbrlen(nbr));
}
