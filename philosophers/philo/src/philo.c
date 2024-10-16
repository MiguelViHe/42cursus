/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/16 15:25:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/functions.h"

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

void	*special_one(t_philo_dt *philo_data)
{
	pthread_mutex_lock(philo_data->fork_l);
	print_action(philo_data, 'f');
	ft_usleep(philo_data->table->tm_sleep);
	pthread_mutex_unlock(philo_data->fork_l);
	return (NULL);
}

void	*th_routine(void *arg)
{
	t_philo_dt	*philo_data;
	t_table_dt	*table;

	philo_data = (t_philo_dt *)arg;
	table = philo_data->table;
	if (table->num_philos == 1)
		return (special_one(philo_data));
	if (philo_data->philo_id % 2 == 0)
		ft_usleep((philo_data->table->tm_eat / 2));
	while (check_all_alive(table) && !check_all_eat(table))
	{
		pthread_mutex_lock(philo_data->fork_l);
		print_action(philo_data, 'f');
		pthread_mutex_lock(philo_data->fork_r);
		print_action(philo_data, 'f');
		action_eat(philo_data);
		pthread_mutex_unlock(philo_data->fork_r);
		pthread_mutex_unlock(philo_data->fork_l);
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

int	main(int argc, char *argv[])
{
	pthread_t		*philos; //liberado!
	pthread_mutex_t	*mutex_forks; //liberado!
	t_table_dt		table; //mutex de table destroyed!
	t_philo_dt		**array_philos_dt; // liberarlo en free_array_philos_dt

	if (are_arguments_correct(argc, argv))
	{
		table = init_table(argc, argv);
		philos = malloc(table.num_philos * sizeof(pthread_t));
		mutex_forks = initialize_mutex_forks(table.num_philos);
		array_philos_dt = init_philos_dt(mutex_forks, &table);
		launch_simulation(philos, array_philos_dt, &table);
		checker_philos(array_philos_dt, &table);
		join_philos(philos, table.num_philos); //aqui se libera philos
		free_philos_dt(array_philos_dt, table.num_philos); //aqui todo lo referente a philos * y ** además de destroy mutex.
		destroy_mutex_table(&table);
		destroy_mutex_forks(mutex_forks, table.num_philos); //aqui se libera mutex_forks
	}
	return (0);
}
