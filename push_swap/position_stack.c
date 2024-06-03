/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:04:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/04 00:07:02 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_position(t_list **stack)
{
	t_list	*current;
	int		i;

	if (!*stack)
		return ;
	i = 0;
	current = *stack;
	while (current)
	{
		current->position = i++;
		current = current->next;
	}
}

void	update_stacks_positions(t_list **stacka, t_list **stackb)
{
	fill_position(stacka);
	fill_position(stackb);
}
