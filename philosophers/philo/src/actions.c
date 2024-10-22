/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:11:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/21 16:52:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/functions.h"

int	print_action(t_philo_dt *ph_dt, char opc)
{
	int		all_alive;
	long	rel_time;

	all_alive = check_all_alive(ph_dt->table);
	if (all_alive && is_philo_alive(ph_dt) && !check_all_eat(ph_dt->table))
	{
		rel_time = rel_time_ms(ph_dt->table->tm_sim_start);
		pthread_mutex_lock(&ph_dt->table->mtx_print);
		if (opc == 'f')
			printf("%ld - %d has taken a fork\n", rel_time, ph_dt->philo_id);
		if (opc == 'e')
			printf("%ld - %d is eating(%d)\n", rel_time, ph_dt->philo_id, ph_dt->tms_ph_ate);
		if (opc == 's')
			printf("%ld - %d  is sleeping\n", rel_time, ph_dt->philo_id);
		if (opc == 't')
			printf("%ld - %d  is thinking\n", rel_time, ph_dt->philo_id);
		pthread_mutex_unlock(&ph_dt->table->mtx_print);
		return (1);
	}
	return (0);
}

void	action_eat(t_philo_dt *philo_data)
{
	if (print_action(philo_data, 'e'))
	{
		if (philo_data->table->n_tms_eat >= 0)
		{
			pthread_mutex_lock(&philo_data->mtx_tms_ph_ate);
			philo_data->tms_ph_ate++;
			pthread_mutex_unlock(&philo_data->mtx_tms_ph_ate);
		}
		set_tm_last_eat(philo_data);
		ft_usleep(philo_data->table->tm_eat);
		print_action(philo_data, 's');
	}
}

void	action_sleep_think(t_philo_dt *philo_data)
{
	ft_usleep(philo_data->table->tm_sleep);
	print_action(philo_data, 't');
}
