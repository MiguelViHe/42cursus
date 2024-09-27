/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/27 15:12:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	*thread_routine(void *arg)
{
	t_philo_dt	*philo_data;

	philo_data = (t_philo_dt *)arg;
	if (philo_data->philo_id % 2 == 0)
		usleep(10);
	while (philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
	{
		printf("Soy %d, esperando a coger mi tenedor left(%d)\n", philo_data->philo_id, philo_data->philo_id);
		pthread_mutex_lock(philo_data->fork_l);
		printf("Soy %d, mi tenedor left(%d) cogido\n", philo_data->philo_id, philo_data->philo_id);
		printf("Soy %d, esperando a coger tenedor right(%d)\n", philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
		pthread_mutex_lock(philo_data->fork_r);
		printf("Soy %d, tenedor right(%d) cogido\n", philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
		printf("%d: empiezo a comer(%d seg)\n", philo_data->philo_id, philo_data->table->tm_eat);
		sleep(philo_data->table->tm_eat);
		if (philo_data->table->n_tms_eat >= 0)
			philo_data->tms_ph_ate++;
		printf("%d: termino comer (%d seg) (comi %d veces)\n", philo_data->philo_id, philo_data->table->tm_eat, philo_data->tms_ph_ate);
		printf("Soy %d, suelto tenedor right(%d)\n", philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
		pthread_mutex_unlock(philo_data->fork_r);
		printf("Soy %d, suelto mi tenedor left(%d)\n", philo_data->philo_id, philo_data->philo_id);
		pthread_mutex_unlock(philo_data->fork_l);
		if (philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
		{
			printf("%d, empiezo a dormir (%d seg)\n", philo_data->philo_id, philo_data->table->tm_sleep);
			sleep(philo_data->table->tm_sleep);
			printf("%d, me despierto (%d seg)\n", philo_data->philo_id, philo_data->table->tm_sleep);
		}
	}
	free(philo_data);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int				i;
	pthread_t		*philos; //liberado!
	pthread_mutex_t	*mutex_forks; //liberado!
	t_table_dt		table;
	t_philo_dt		*philo_data; // liberarlo en cada thread

	if (argc != 5 && argc != 6)
		printf("Bad num of arguments. Try again\n");
	else
	{
		i = 0;
		table = init_table(argc, argv);
		philos = malloc(table.num_philos * sizeof(pthread_t));
		mutex_forks = initialize_mutex_forks(table.num_philos);
		while (i < table.num_philos)
		{
			philo_data = init_philo(mutex_forks, i, &table);
			if (pthread_create(&philos[i], NULL, thread_routine, philo_data) != 0)
				return (-1);
			i++;
		}
		join_philos(philos, table.num_philos); //aqui se libera philos
		destroy_mutex_forks(mutex_forks, table.num_philos); //aqui se libera mutex_forks
	}
	return (0);
}
