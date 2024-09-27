/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:00:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/27 15:09:07 by mvidal-h         ###   ########.fr       */
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

typedef struct s_table_dt
{
	int	num_philos;
	int	tm_die;
	int	tm_eat;
	int	tm_sleep;
	int	n_tms_eat;
}	t_table_dt;

typedef struct s_philo_data
{
	int				philo_id;
	int				tms_ph_ate;
	t_table_dt		*table;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
}	t_philo_dt;

//mutex.c

pthread_mutex_t	*initialize_mutex_forks(int num_forks);
void			destroy_mutex_forks(pthread_mutex_t	*mutex_forks, int n_forks);

//initialization.c

t_table_dt		init_table(int argc, char *argv[]);
t_philo_dt		*init_philo(pthread_mutex_t *mtx_forks, int phi, t_table_dt *t);

#endif