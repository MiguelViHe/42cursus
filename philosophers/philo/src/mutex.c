/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:42:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/27 15:09:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*initialize_mutex_forks(int num_forks)
{
	int				i;
	pthread_mutex_t	*mutex_forks;

	i = 0;
	mutex_forks = malloc(num_forks * sizeof(pthread_mutex_t));
	while (i < num_forks)
	{
		pthread_mutex_init(&mutex_forks[i], NULL);
		i++;
	}
	return (mutex_forks);
}

void	destroy_mutex_forks(pthread_mutex_t	*mutex_forks, int n_forks)
{
	int	i;

	i = 0;
	while (i < n_forks)
	{
		pthread_mutex_destroy(&mutex_forks[i]);
		i++;
	}
	free(mutex_forks);
}
