/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/17 18:21:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/functions.h"
#include "../includes/functions_utils.h"

static int	is_arg_number(const char *str)
{
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_isdigit(str[i]))
		return (1);
	return (0);
}

static int	check_argv_numbers(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_arg_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_argv_negative(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atol(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_argv_zero_invalid(int argc, char *argv[])
{
	if (ft_atol(argv[1]) == 0)
	{
		printf("Num of philos can't be zero. Try again\n");
		return (1);
	}
	if (argc == 6 && ft_atol(argv[5]) == 0)
		return (1);
	return (0);
}

int	are_arguments_correct(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("Bad num of arguments. 5 o 6 are needed. Try again\n");
		return (0);
	}
	else if (!check_argv_numbers(argc, argv))
	{
		printf("Arguments must be numbers. Try again\n");
		return (0);
	}
	else if (check_argv_negative(argc, argv))
	{
		printf("Negative arguments are not allowed. Try again\n");
		return (0);
	}
	else if (check_argv_zero_invalid(argc, argv))
		return (0);
	return (1);
}
