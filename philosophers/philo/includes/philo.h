/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:00:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/25 17:48:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//malloc, free, exit, rand
# include <stdlib.h>

//usleep, sleep
# include <unistd.h>

//O_RDONLY
# include <fcntl.h>

//printf
# include <stdio.h>

# include <pthread.h>

	typedef struct s_table_data
	{
		int	num_philos;
		int	t_die;
		int	t_eat;
		int	t_sleep;
		int	n_t_eat;
	} t_table_data;

	typedef struct s_philo_data
	{
		int				philo_id;
		t_table_data	*table;
		pthread_mutex_t	*fork_l;
		pthread_mutex_t	*fork_r;
	} t_philo_data;


#endif