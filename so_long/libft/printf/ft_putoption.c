/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:27:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/05 10:04:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putoption(int fd, char option, va_list args)
{
	if (option == 'c')
		return (ft_putchar(fd, va_arg(args, int)));
	else if (option == 's')
		return (ft_putstr(fd, va_arg(args, char *)));
	else if (option == 'p')
		return (ft_putptr(fd, va_arg(args, unsigned long long)));
	else if (option == 'd' || option == 'i')
		return (ft_digit(fd, va_arg(args, int)));
	else if (option == 'u')
		return (ft_base(fd, va_arg(args, unsigned int), "0123456789"));
	else if (option == 'x')
		return (ft_base(fd, va_arg(args, unsigned int), "0123456789abcdef"));
	else if (option == 'X')
		return (ft_base(fd, va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (option == '%')
		return (ft_putchar(fd, option));
	return (0);
}