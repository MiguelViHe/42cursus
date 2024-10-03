/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:00:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/03 18:08:03 by mvidal-h         ###   ########.fr       */
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

//gettimeofday
#include <sys/time.h>

typedef struct s_table_dt
{
	int		num_philos;
	int		tm_die;
	int		tm_eat;
	int		tm_sleep;
	int		n_tms_eat;
	long	tm_sim_start;
}	t_table_dt;

typedef struct s_philo_data
{
	int				philo_id;
	int				tms_ph_ate;
	long			tm_last_eat;
	int				is_alive;
	t_table_dt		*table;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
}	t_philo_dt;

//mutex.c

pthread_mutex_t	*initialize_mutex_forks(int num_forks);
void			destroy_mutex_forks(pthread_mutex_t	*mutex_forks, int n_forks);

//time.c
long	abs_time_ms(void);
long	rel_time_ms(long tm_sim_start);

//initialization.c

t_table_dt		init_table(int argc, char *argv[]);
t_philo_dt	**initialize_philos_dt(pthread_mutex_t *mtx_forks, t_table_dt *t);
void	init_time_start(t_table_dt *table);

#endif