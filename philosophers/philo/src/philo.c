/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/24 18:08:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/functions.h"

t_philo_data *init_philo(pthread_mutex_t *mtx_forks, int philo, int num_philos)
{
	t_philo_data	*philo_data;

	philo_data = malloc(sizeof(t_philo_data));
	philo_data->philo_id = philo;
	philo_data->fork_l = &mtx_forks[philo];
	philo_data->fork_r = &mtx_forks[(philo + 1) % num_philos];
	return (philo_data);
}

pthread_mutex_t	*initialize_mutex_forks(int num_forks)
{
	int	i;
	pthread_mutex_t	*mutex_forks;
	
	i = 0;
	mutex_forks = malloc(num_forks * sizeof(pthread_mutex_t));
	while (i < num_forks)
		pthread_mutex_init(&mutex_forks[i], NULL);
	return (mutex_forks);
}

void	destroy_mutex_forks(pthread_mutex_t	*mutex_forks, int num_forks)
{
	int	i;
	
	i = 0;
	while (i < num_forks)
		pthread_mutex_destroy(&mutex_forks[i]);
	free(mutex_forks);
}

void	join_philos(pthread_t *philos, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(philos[i], NULL);
		printf("join %d\n", i);
		i++;
	}
	free(philos);
}

void	*thread_routine2(void *arg)
{
	t_philo_data	*thread_data;

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
	pthread_t		*philos; //liberado!
	pthread_mutex_t	*mutex_forks; //liberado!
	int				num_philos;
	t_philo_data	*philo_data; // liberarlo en cada thread
	int				i;
	
	if (argc != 5 && argc != 6)
		printf("Bad num of arguments. Try again\n");
	else
	{
		i = 0;
		num_philos = ft_atoi(argv[1]);
		philos = malloc(num_philos * sizeof(pthread_t));
		mutex_forks = initialize_mutex_forks(num_philos);
		while (i < num_philos)
		{
			philo_data = initialize_philo(mutex_forks, i + 1);
			if (pthread_create(&philos[i], NULL, thread_routine2, philo_data) != 0)
				return (-1);
			i++;
		}
		join_philos(philos, num_philos); //aqui se libera philos
		destroy_mutex_forks(mutex_forks, num_philos); //aqui se libera mutex_forks
	}
	return (0);
}
