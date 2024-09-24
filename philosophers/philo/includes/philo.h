/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:00:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/24 15:44:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//libft
# include "libft/libft.h"

//malloc, free, exit, rand
# include <stdlib.h>

//O_RDONLY
# include <fcntl.h>

# include <pthread.h>

	typedef struct s_philo_data
	{
		int				philo_id;
		pthread_mutex_t	*fork_l;
		pthread_mutex_t	*fork_r;
	} t_philo_data;

#endif