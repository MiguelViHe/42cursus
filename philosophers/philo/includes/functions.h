/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:16:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/15 10:53:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

//functions/ft_atol.c
long	ft_atol(const char *str);

//functions/ft_atoi.c
int		ft_atoi(const char *str);

//functions/ft_atost.c
size_t	ft_atost(const char *str);

//functions/ft_usleep.c
int		ft_usleep(size_t milliseconds);
#endif