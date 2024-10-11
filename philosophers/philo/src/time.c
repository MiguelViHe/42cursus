/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:10:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/11 12:31:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	abs_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

size_t	rel_time_ms(size_t tm_sim_start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - tm_sim_start);
}

void	set_tm_last_eat(t_philo_dt *philo_data)
{
	if (is_philo_alive(philo_data))
	{
		pthread_mutex_lock(&philo_data->mtx_tm_last_eat);
		philo_data->tm_last_eat = abs_time_ms();
		pthread_mutex_unlock(&philo_data->mtx_tm_last_eat);
	}
}
