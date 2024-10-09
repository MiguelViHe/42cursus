/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:35:49 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/09 12:30:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_array_philos_dt(t_philo_dt	**array_philos_dt, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&array_philos_dt[i]->mtx_tm_last_eat);
		pthread_mutex_destroy(&array_philos_dt[i]->mtx_tms_ph_ate);
		free(array_philos_dt[i]);
		i++;
	}
	free(array_philos_dt);
}
