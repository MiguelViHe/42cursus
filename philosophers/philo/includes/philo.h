/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:00:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/17 18:18:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//malloc, free, exit, rand
# include <stdlib.h>

//usleep, sleep, size_t
# include <unistd.h>

//O_RDONLY
# include <fcntl.h>

//printf
# include <stdio.h>

# include <pthread.h>

//gettimeofday
# include <sys/time.h>

typedef struct s_table_dt
{
	int				num_philos;
	size_t			tm_die;
	size_t			tm_eat;
	size_t			tm_sleep;
	int				n_tms_eat;
	size_t			tm_sim_start;
	int				all_alive;
	pthread_mutex_t	mtx_all_alive; //destroyed.
	int				all_eat;
	pthread_mutex_t	mtx_all_eat; //destroyed.
}	t_table_dt;

typedef struct s_philo_data
{
	int				philo_id;
	int				tms_ph_ate;
	pthread_mutex_t	mtx_tms_ph_ate; //destroyed
	size_t			tm_last_eat;
	pthread_mutex_t	mtx_tm_last_eat; //destroyed
	t_table_dt		*table;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
}	t_philo_dt;

//check_args.c
int				are_arguments_correct(int argc, char *argv[]);

//mutex.c
pthread_mutex_t	*initialize_mutex_forks(int num_forks);
void			destroy_mutex_forks(pthread_mutex_t	*mutex_forks, int n_forks);
void			destroy_mutex_table(t_table_dt *table);

//time.c
size_t			abs_time_ms(void);
size_t			rel_time_ms(size_t tm_sim_start);
void			set_tm_last_eat(t_philo_dt *philo_data);

//initialization.c
t_table_dt		init_table(int argc, char *argv[]);
t_philo_dt		**init_philos_dt(pthread_mutex_t *mtx_forks, t_table_dt *t);
void			init_time_start(t_table_dt *table);

//checker_referee.c
int				is_philo_alive(t_philo_dt *philo_data);
void			checker_philos(t_philo_dt **phi_dt, t_table_dt *table);

//freeing.c
void			free_philos_dt(t_philo_dt	**array_philos_dt, int num_philos);

//actions.c
int				print_action(t_philo_dt *ph_dt, char opc);
void			action_eat(t_philo_dt *philo_data);
void			action_sleep_think(t_philo_dt *philo_data);

//checker_philos.c
int				check_all_alive(t_table_dt *table);
int				check_all_eat(t_table_dt *table);

#endif