/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:51:58 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/15 11:49:48 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// Improved version of sleep function
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = abs_time_ms();
	while ((abs_time_ms() - start) < milliseconds)
		usleep(500);
	return (0);
}
