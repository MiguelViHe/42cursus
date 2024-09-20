/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/20 18:09:59 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>  //O_RDONLY
#include <pthread.h>
#include "../includes/functions.h"

typedef struct s_thread_data{
    pthread_mutex_t	*mutex;
    int				thread_id;
} t_thread_data;

void	*thread_routine2(void *arg)
{
	t_thread_data	*thread_data;

	thread_data = (t_thread_data *)arg;
	printf("puerta esperando: %d\n", thread_data->thread_id);
	pthread_mutex_lock(thread_data->mutex);
	printf("puerta dentro: %d\n", thread_data->thread_id);
	sleep(5);
	printf("puerta salgo: %d\n", thread_data->thread_id);
	pthread_mutex_unlock(thread_data->mutex);
	free(thread_data);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t		*forks;
	int				num_forks;
	t_thread_data	*thread_data;
	pthread_mutex_t	mutex;
	int				i;
	
	if (argc != 5 && argc != 6)
	{
		printf("Bad arguments, Try:\n");
		printf("./philo num_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]");
	}
	else
	{
		i = 0;
		num_forks = ft_atoi(argv[1]);
		forks = malloc(num_forks * sizeof(pthread_t));
		pthread_mutex_init(&mutex, NULL);
		while (i < num_forks)
		{
			printf("entro aqui\n");
			thread_data = malloc(sizeof(t_thread_data));
			thread_data->thread_id = i;
			thread_data->mutex = &mutex;
			if (pthread_create(&forks[i], NULL, thread_routine2, thread_data) != 0)
				return (-1);
			i++;
		}
		i = 0;
		while (i < num_forks)
		{
			pthread_join(forks[i], NULL);
			printf("join %d\n", i);
			i++;
		}
		free(forks);
		pthread_mutex_destroy(&mutex);
	}
	return (0);
}
