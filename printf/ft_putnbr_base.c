/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:25:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/15 18:23:25 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h" //COMPROBAR SI SE ADMITE PARA ft_strlen.Si no crear en utils

int	ft_nbrlen_base(unsigned int nbr, size_t baselen)
{
	unsigned int    counter;

	counter = 0;
	while (nbr)
	{
		counter++;
		nbr /= baselen;
	}
	return (counter);
}

int ft_putnbr_base(unsigned int nbr, char *base)
{
	size_t    baselen;
	
	if (!base)
		return (0);
	baselen = ft_strlen(base);//include "libft.h"
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr >= baselen)
	{
		ft_putnbr_base(nbr / baselen, base);
		ft_putnbr_base(nbr % baselen, base);
	}
	else
		ft_putchar(base[nbr]);
	return(ft_nbrlen_base(nbr, baselen));
}