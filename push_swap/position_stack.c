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

/*Fill the position of every node of the stack.
Position is the current position in the stack. It change with every movement*/
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

/*Update the position of both stacks. Used in push movements*/
void	update_stacks_positions(t_list **stacka, t_list **stackb)
{
	fill_position(stacka);
	fill_position(stackb);
}
