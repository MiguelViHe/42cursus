/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:50:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/09 12:33:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_philo_alive(t_philo_dt *philo_data)
{
	long	curr_time_ms;
	long	tm_sim_start;
	long	tm_last_eat;
	long	tm_die;

	tm_sim_start = philo_data->table->tm_sim_start;
	tm_die = philo_data->table->tm_die;
	curr_time_ms = abs_time_ms();
	pthread_mutex_lock(&philo_data->mtx_tm_last_eat);
	tm_last_eat = philo_data->tm_last_eat;
	pthread_mutex_unlock(&philo_data->mtx_tm_last_eat);
	if (tm_last_eat == 0)
		return ((curr_time_ms - tm_sim_start) <= tm_die);
	else
		return ((curr_time_ms - tm_last_eat) <= tm_die);
}

void	check_philos_alive(t_philo_dt **phi_dt, t_table_dt *table)
{
	int	i;

	usleep(1000);
	while (table->all_alive)
	{
		printf("%ld - chequeo hijos vivos..\n", rel_time_ms(table->tm_sim_start));
		i = 0;
		while (table->all_alive && i < table->num_philos)
		{
			if (!is_philo_alive(phi_dt[i]))
			{
				pthread_mutex_lock(&table->mtx_all_alive);
				table->all_alive = 0;
				printf("%ld - %d died\n", rel_time_ms(table->tm_sim_start), phi_dt[i]->philo_id);
				pthread_mutex_unlock(&table->mtx_all_alive);
			}
			i++;
		}
		usleep(1000);
	}
}
