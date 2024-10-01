/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/01 12:42:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_philo_alive(t_philo_dt *philo_data)
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	if (philo_data->tm_last_eat == 0)
		philo_data->is_alive = (tv.tv_sec - philo_data->table->tm_sim_start) <= philo_data->table->tm_die;
	else
		philo_data->is_alive = (tv.tv_sec - philo_data->tm_last_eat) <= philo_data->table->tm_die;
	if (philo_data->is_alive)
		philo_data->tm_last_eat = tv.tv_sec;
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

void	*th_routine(void *arg)
{
	t_philo_dt	*philo_data;

	philo_data = (t_philo_dt *)arg;
	if (philo_data->philo_id % 2 == 0)
		usleep(50);
	while (philo_data->is_alive && philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
	{
		printf("Soy %d, esperando a coger mi tenedor left(%d)\n", philo_data->philo_id, philo_data->philo_id);
		pthread_mutex_lock(philo_data->fork_l);
		printf("Soy %d, mi tenedor left(%d) cogido\n", philo_data->philo_id, philo_data->philo_id);
		printf("Soy %d, esperando a coger tenedor right(%d)\n", philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
		pthread_mutex_lock(philo_data->fork_r);
		printf("Soy %d, tenedor right(%d) cogido\n", philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
		check_philo_alive(philo_data);
		if (philo_data->is_alive)
		{
			printf("%d: empiezo a comer(%d seg)\n", philo_data->philo_id, philo_data->table->tm_eat);
			sleep(philo_data->table->tm_eat);
			if (philo_data->table->n_tms_eat >= 0)
				philo_data->tms_ph_ate++;
			printf("%d: termino comer (%d seg) (comi %d veces)\n", philo_data->philo_id, philo_data->table->tm_eat, philo_data->tms_ph_ate);
		}
		printf("Soy %d, suelto tenedor right(%d)\n", philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
		pthread_mutex_unlock(philo_data->fork_r);
		printf("Soy %d, suelto mi tenedor left(%d)\n", philo_data->philo_id, philo_data->philo_id);
		pthread_mutex_unlock(philo_data->fork_l);
		if (philo_data->is_alive && philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
		{
			printf("%d, empiezo a dormir (%d seg)\n", philo_data->philo_id, philo_data->table->tm_sleep);
			sleep(philo_data->table->tm_sleep);
			printf("%d, me despierto (%d seg)\n", philo_data->philo_id, philo_data->table->tm_sleep);
		}
	}
	if (!philo_data->is_alive)
		printf("Soy %d y he muerto\n", philo_data->philo_id);
	free(philo_data);
	return (NULL);
}

int	launch_simulation(pthread_t *phi, t_philo_dt **phi_dt, int num_phi)
{
	int	i;

	i = 0;
	while (i < num_phi)
	{
		if (pthread_create(&phi[i], NULL, th_routine, phi_dt[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pthread_t		*philos; //liberado!
	pthread_mutex_t	*mutex_forks; //liberado!
	t_table_dt		table;
	t_philo_dt		**array_philos_dt; // liberarlo en cada thread y al final de main!

	if (argc != 5 && argc != 6)
		printf("Bad num of arguments. Try again\n");
	else
	{
		table = init_table(argc, argv);
		philos = malloc(table.num_philos * sizeof(pthread_t));
		mutex_forks = initialize_mutex_forks(table.num_philos);
		array_philos_dt = initialize_philos_dt(mutex_forks, &table);
		init_time_start(&table);
		launch_simulation(philos, array_philos_dt, table.num_philos);
		join_philos(philos, table.num_philos); //aqui se libera philos
		free(array_philos_dt);
		destroy_mutex_forks(mutex_forks, table.num_philos); //aqui se libera mutex_forks
	}
	return (0);
}
