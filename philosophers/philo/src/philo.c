/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/07 18:06:33 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_philos(pthread_t *philos, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(philos[i], NULL);
		printf("join %d\n", i); //borrar
		i++;
	}
	free(philos);
}

void	*th_routine(void *arg) //REVISAR PARA USAR LOS MUTEX. LO MISMO FUNCION FT_USLEEP
{
	t_philo_dt	*philo_data;
	t_table_dt	*table;

	philo_data = (t_philo_dt *)arg;
	table = philo_data->table;
	if (philo_data->philo_id % 2 == 0)
		usleep((philo_data->table->tm_eat / 2) * 1000);
	while (table->all_alive && philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
	{
		pthread_mutex_lock(philo_data->fork_l);
		printf("%ld - %d has taken a fork(%d)\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, philo_data->philo_id);
		pthread_mutex_lock(philo_data->fork_r);
		printf("%ld - %d has taken a fork(%d)\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
		if (table->all_alive) //PARA LEER is_alive LO MISMO HAY QUE USAR EL MUTEX PARA LEERLA.
		{
			set_tm_last_eat(philo_data);
			printf("%ld - %d is eating\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id);
			usleep(philo_data->table->tm_eat * 1000);
			if (philo_data->table->n_tms_eat >= 0)
				philo_data->tms_ph_ate++;
		}
		pthread_mutex_unlock(philo_data->fork_r);
		pthread_mutex_unlock(philo_data->fork_l);
		if (table->all_alive && philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
		{
			printf("%ld - %d  is sleeping\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id);
			usleep(philo_data->table->tm_sleep * 1000);
			printf("%ld - %d,  is thinking\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id);
		}
	}
	return (NULL);
}

// void	*th_routine(void *arg)
// {
// 	t_philo_dt		*philo_data;

// 	philo_data = (t_philo_dt *)arg;
// 	if (philo_data->philo_id % 2 == 0)
// 		usleep(50 * 1000);
// 	while (philo_data->is_alive && philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
// 	{
// 		pthread_mutex_lock(philo_data->fork_l);
// 		printf("%ld - Soy %d, mi tenedor left(%d) cogido\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, philo_data->philo_id);
// 		pthread_mutex_lock(philo_data->fork_r);
// 		printf("%ld - Soy %d, tenedor right(%d) cogido\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, ((philo_data->philo_id) % philo_data->table->num_philos) + 1);
// 		check_philo_alive(philo_data);
// 		if (philo_data->is_alive)
// 		{
// 			printf("%ld - %d: empiezo a comer(%d ms)\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, philo_data->table->tm_eat);
// 			usleep(philo_data->table->tm_eat * 1000);
// 			if (philo_data->table->n_tms_eat >= 0)
// 				philo_data->tms_ph_ate++;
// 			printf("%ld - %d: termino comer (%d ms) (comi %d veces)\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, philo_data->table->tm_eat, philo_data->tms_ph_ate);
// 		}
// 		pthread_mutex_unlock(philo_data->fork_r);
// 		pthread_mutex_unlock(philo_data->fork_l);
// 		if (philo_data->is_alive && philo_data->tms_ph_ate != philo_data->table->n_tms_eat)
// 		{
// 			printf("%ld - %d, empiezo a dormir (%d ms)\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, philo_data->table->tm_sleep);
// 			usleep(philo_data->table->tm_sleep * 1000);
// 			printf("%ld - %d, me despierto (%d ms)\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id, philo_data->table->tm_sleep);
// 		}
// 	}
// 	if (!philo_data->is_alive)
// 		printf("%ld - Soy %d y he muerto\n", rel_time_ms(philo_data->table->tm_sim_start), philo_data->philo_id);
// 	free(philo_data);
// 	return (NULL);
// }

int	launch_simulation(pthread_t *phi, t_philo_dt **phi_dt, t_table_dt *table)
{
	int	i;

	i = 0;
	init_time_start(table);
	while (i < table->num_philos)
	{
		if (pthread_create(&phi[i], NULL, th_routine, phi_dt[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pthread_t		*philos; //liberado!
	pthread_mutex_t	*mutex_forks; //liberado!
	t_table_dt		table; //hay que dewtroy el mutex de table
	t_philo_dt		**array_philos_dt; // liberarlo en free_array_philos_dt

	if (argc != 5 && argc != 6)
		printf("Bad num of arguments. Try again\n");
	else
	{
		table = init_table(argc, argv);
		philos = malloc(table.num_philos * sizeof(pthread_t));
		mutex_forks = initialize_mutex_forks(table.num_philos);
		array_philos_dt = initialize_philos_dt(mutex_forks, &table);
		launch_simulation(philos, array_philos_dt, &table);
		check_philos_alive(array_philos_dt, &table);
		join_philos(philos, table.num_philos); //aqui se libera philos
		free_array_philos_dt(array_philos_dt, table.num_philos); //aqui todo lo referente a philos * y ** además de destroy mutex.
		destroy_mutex_table(&table);
		destroy_mutex_forks(mutex_forks, table.num_philos); //aqui se libera mutex_forks
	}
	return (0);
}
