/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_referee.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:50:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/15 17:51:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/functions.h"

static int	n_tms_eat_reached(t_philo_dt *philo_data)
{
	int	tms_ate;
	int	tms_eat;

	tms_eat = philo_data->table->n_tms_eat;
	if (tms_eat < 0)
		return (0);
	pthread_mutex_lock(&philo_data->mtx_tms_ph_ate);
	tms_ate = philo_data->tms_ph_ate;
	pthread_mutex_unlock(&philo_data->mtx_tms_ph_ate);
	if (tms_ate >= tms_eat)
		return (1);
	return (0);
}

static int	all_finish_eating(t_philo_dt **phi_dt)
{
	int			i;
	int			result;
	t_table_dt	*table;

	i = 0;
	result = 0;
	table = phi_dt[0]->table;
	while (i < table->num_philos)
	{
		if (n_tms_eat_reached(phi_dt[i]))
			result++;
		i++;
	}
	if (result == table->num_philos)
	{
		pthread_mutex_lock(&table->mtx_all_eat);
		table->all_eat = 1;
		pthread_mutex_unlock(&table->mtx_all_eat);
		return (1);
	}
	return (0);
}

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

void	checker_philos(t_philo_dt **phi_dt, t_table_dt *table)
{
	int		i;
	size_t	rel_time;

	ft_usleep(1);
	while (table->all_alive && !all_finish_eating(phi_dt)) //REVISAR
	{
		//printf("%ld - chequeo hijos vivos..\n", rel_time_ms(table->tm_sim_start));
		i = 0;
		while (table->all_alive && i < table->num_philos)
		{
			if (!is_philo_alive(phi_dt[i]))
			{
				pthread_mutex_lock(&table->mtx_all_alive);
				table->all_alive = 0;
				rel_time = rel_time_ms(table->tm_sim_start);
				printf("%ld - %d died\n", rel_time, phi_dt[i]->philo_id);
				pthread_mutex_unlock(&table->mtx_all_alive);
			}
			i++;
		}
		ft_usleep(1);
	}
}
