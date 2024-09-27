/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:45:49 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/27 15:11:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/functions.h"

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
	return (table);
}

t_philo_dt	*init_philo(pthread_mutex_t *mtx_forks, int phi, t_table_dt *t)
{
	t_philo_dt	*philo_data;

	philo_data = malloc(sizeof(t_philo_dt));
	philo_data->philo_id = phi + 1;
	philo_data->tms_ph_ate = 0;
	philo_data->table = t;
	philo_data->fork_l = &mtx_forks[phi];
	philo_data->fork_r = &mtx_forks[(phi + 1) % t->num_philos];
	return (philo_data);
}
