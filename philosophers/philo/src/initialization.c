/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:45:49 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/03 18:15:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/functions.h"

void	init_time_start(t_table_dt *table)
{
	table->tm_sim_start = abs_time_ms();
}

t_table_dt	init_table(int argc, char *argv[])
{
	t_table_dt	table;

	table.num_philos = ft_atoi(argv[1]);
	table.tm_die = ft_atoi(argv[2]);
	table.tm_eat = ft_atoi(argv[3]);
	table.tm_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table.n_tms_eat = ft_atoi(argv[5]);
	else
		table.n_tms_eat = -1;
	table.tm_sim_start = 0;
	return (table);
}

t_philo_dt	*init_philo(pthread_mutex_t *mtx_forks, int phi, t_table_dt *t)
{
	t_philo_dt	*philo_data;

	philo_data = malloc(sizeof(t_philo_dt));
	philo_data->philo_id = phi + 1;
	philo_data->tms_ph_ate = 0;
	philo_data->tm_last_eat = 0;
	philo_data->is_alive = 1;
	philo_data->table = t;
	philo_data->fork_l = &mtx_forks[phi];
	philo_data->fork_r = &mtx_forks[(phi + 1) % t->num_philos];
	return (philo_data);
}

t_philo_dt	**initialize_philos_dt(pthread_mutex_t *mtx_forks, t_table_dt *t)
{
	t_philo_dt	**array_philos_dt;
	int			philo;

	array_philos_dt = malloc(t->num_philos * sizeof(t_philo_dt *));
	philo = 0;
	while (philo < t->num_philos)
	{
		array_philos_dt[philo] = init_philo(mtx_forks, philo, t);
		philo++;
	}
	return (array_philos_dt);
}
