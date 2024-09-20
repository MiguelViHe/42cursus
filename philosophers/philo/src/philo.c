/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/20 14:08:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
# include <fcntl.h>  //O_RDONLY
#include <pthread.h>
#include "../includes/functions.h"

void	*thread_routine(void *arg)
{
	int	i;
	int	nbr_lines;
	int	fd;
	char str[] = "nueva_linea\n";

	nbr_lines = *(int *)arg;
	i = 0;
	printf("El hilo comienza su ejecución\n");
	fd = open("archivo.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd != -1)
	{
		while(i < nbr_lines)
		{
			write(fd, str, sizeof(str) - 1);
			i++;
		}
		close(fd);
	}
	printf("El hilo finaliza su ejecución\n");
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	thread_1;
	int			value;
	
	if (argc != 5 && argc != 6)
	{
		printf("Bad arguments, Try:\n");
		printf("./philo num_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]");
	}
	else
	{
		value = ft_atoi(argv[1]);
		if (pthread_create(&thread_1, NULL, &thread_routine, &value) != 0)
			return (-1);
		pthread_join(thread_1, NULL);
	}
	return (0);
}
