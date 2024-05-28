/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:23:38 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/28 10:23:39 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(t_list *stack)
{
	t_list	*current;
	t_list	*aux;

	if (!stack)
		return (-1);
	current = stack;
	while (current)
	{
		aux = current->next;
		while (aux)
		{
			if (*(int *)current->content == *(int *)aux->content)
				return (free_stack(&stack), 1);
			aux = aux->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_arg_integer(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_limits_integer(long number)
{
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}
