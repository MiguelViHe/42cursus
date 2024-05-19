/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:56:30 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/14 13:55:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **stack)
{
	t_list  *min;
	t_list  *current;

	min = NULL;
	if(!*stack)
		return (NULL);
	current = *stack;
	while (current)
	{
		if (current->index == -1 && (min == NULL || 
			*(int *)current->content < *(int *)min->content))
			min = current;
		current = current->next;
	}
	return (min);
}

void	fill_index(t_list **stack)
{
	t_list	*min;
	int		i;

	if(!*stack)
		return;
	i = 1;
	min = find_min(stack);
	while (min)
	{
		min->index = i++;
		min = find_min(stack);
	}
}

void	fill_position(t_list **stack)
{
	t_list	*current;
	int		i;

	if(!*stack)
		return;
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