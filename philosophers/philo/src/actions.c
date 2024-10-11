/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:11:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/10 19:27:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_philo_dt *ph_dt, char opc)
{
	int		all_alive;
	long	rel_time;

	pthread_mutex_lock(&ph_dt->table->mtx_all_alive);
	all_alive = ph_dt->table->all_alive;
	pthread_mutex_unlock(&ph_dt->table->mtx_all_alive);
	if (all_alive && is_philo_alive(ph_dt) && !check_all_eat(ph_dt->table))//REVISAR
	{
		rel_time = rel_time_ms(ph_dt->table->tm_sim_start);
		if (opc == 'f')
			printf("%ld - %d has taken a fork\n", rel_time, ph_dt->philo_id);
		if (opc == 'e')
			printf("%ld - %d is eating(%d)\n", rel_time, ph_dt->philo_id, ph_dt->tms_ph_ate);
		if (opc == 's')
			printf("%ld - %d  is sleeping\n", rel_time, ph_dt->philo_id);
		if (opc == 't')
			printf("%ld - %d  is thinking\n", rel_time, ph_dt->philo_id);
	}
}

int	check_all_alive(t_table_dt *table)
{
	int	aa;

	pthread_mutex_lock(&table->mtx_all_alive);
	aa = table->all_alive;
	pthread_mutex_unlock(&table->mtx_all_alive);
	return (aa);
}

int	check_all_eat(t_table_dt *table) //REVISAR
{
	int	ae;

	pthread_mutex_lock(&table->mtx_all_eat);
	ae = table->all_eat;
	pthread_mutex_unlock(&table->mtx_all_eat);
	return (ae);
}

int	n_tms_eat_reached(t_philo_dt *philo_data)
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

void	action_eat(t_philo_dt *philo_data)
{
	if (philo_data->table->n_tms_eat >= 0)
	{
		pthread_mutex_lock(&philo_data->mtx_tms_ph_ate);
		philo_data->tms_ph_ate++;
		pthread_mutex_unlock(&philo_data->mtx_tms_ph_ate);
	}
	print_action(philo_data, 'e');
	set_tm_last_eat(philo_data);
	usleep(philo_data->table->tm_eat * 1000);
}

void	action_sleep_think(t_philo_dt *philo_data)
{
	print_action(philo_data, 's');
	usleep(philo_data->table->tm_sleep * 1000);
	print_action(philo_data, 't');
}