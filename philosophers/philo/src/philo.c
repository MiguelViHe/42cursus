/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/09 12:34:00 by mvidal-h         ###   ########.fr       */
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
		printf("join %d\n", i); //borrar
		i++;
	}
	free(philos);
}

void	*th_routine(void *arg)
{
	t_philo_dt	*philo_data;
	t_table_dt	*table;

	philo_data = (t_philo_dt *)arg;
	table = philo_data->table;
	if (philo_data->philo_id % 2 == 0)
		usleep((philo_data->table->tm_eat / 2) * 1000);
	while (check_all_alive(table) && !n_tms_eat_reached(philo_data))
	{
		pthread_mutex_lock(philo_data->fork_l);
		print_action(philo_data, 'f');
		pthread_mutex_lock(philo_data->fork_r);
		print_action(philo_data, 'f');
		if (check_all_alive(table))
			action_eat(philo_data);
		pthread_mutex_unlock(philo_data->fork_r);
		pthread_mutex_unlock(philo_data->fork_l);
		if (check_all_alive(table) && !n_tms_eat_reached(philo_data))
			action_sleep_think(philo_data);
	}
	return (NULL);
}

int	launch_simulation(pthread_t *phi, t_philo_dt **phi_dt, t_table_dt *table)
{
	int	i;

	i = 0;
	init_time_start(table);
	while (i < table->num_philos)
	{
		if (pthread_create(&phi[i], NULL, th_routine, phi_dt[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[]) // PROBAR CON ./philo 3 100 50 10
{
	pthread_t		*philos; //liberado!
	pthread_mutex_t	*mutex_forks; //liberado!
	t_table_dt		table; //mutex de table destroyed!
	t_philo_dt		**array_philos_dt; // liberarlo en free_array_philos_dt

	if (argc != 5 && argc != 6)
		printf("Bad num of arguments. Try again\n");
	else
	{
		table = init_table(argc, argv);
		philos = malloc(table.num_philos * sizeof(pthread_t));
		mutex_forks = initialize_mutex_forks(table.num_philos);
		array_philos_dt = init_philos_dt(mutex_forks, &table);
		launch_simulation(philos, array_philos_dt, &table);
		check_philos_alive(array_philos_dt, &table);
		join_philos(philos, table.num_philos); //aqui se libera philos
		printf("llego aqui 1\n");
		free_philos_dt(array_philos_dt, table.num_philos); //aqui todo lo referente a philos * y ** además de destroy mutex.
		printf("llego aqui 2\n");
		destroy_mutex_table(&table);
		printf("llego aqui 3\n");
		destroy_mutex_forks(mutex_forks, table.num_philos); //aqui se libera mutex_forks
		printf("llego aqui 4\n");
	}
	return (0);
}
