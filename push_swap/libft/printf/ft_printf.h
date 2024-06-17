/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:46:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/17 12:32:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
//# include <unistd.h> //Comentadas al incluirlo el libft porque ya la tiene
//# include <stdlib.h> //Comentadas al incluirlo el libft porque ya la tiene
//# include "libft/libft.h" //ADDED

int		ft_printf(char const *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
//size_t	ft_strlen(const char *s); //ADDED
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize); //ADDED
int		ft_digit(int nbr);
int		ft_putnbr(int nbr);
int		ft_nbrlen(int nbr);
int		ft_base(unsigned int nbr, char *base);
int		ft_putnbr_base(unsigned int nbr, char *base, size_t baselen);
int		ft_nbrlen_base(unsigned int nbr, size_t baselen);
int		ft_putptr(unsigned long long nbr);
int		ft_putptr_hexa(unsigned long long nbr);
int		ft_ptrlen_hexa(unsigned long long nbr);

#endif
