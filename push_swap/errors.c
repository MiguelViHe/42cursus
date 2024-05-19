/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:23:38 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/19 22:48:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(t_list *stack)
{
	t_list	*current;

	if (!stack)
		return (-1);
	current = stack;
	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (*(int *)stack->content == *(int *)current->content)
				return (1);
			current = current->next;
		}
		stack = stack->next;
	}
	return (0);
}