/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:06:33 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/14 18:19:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
