/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:56:30 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/04 00:06:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Return the node with the min index that still has not index number */
static t_list	*find_min(t_list **stack)
{
	t_list	*min;
	t_list	*current;

	min = NULL;
	if (!*stack)
		return (NULL);
	current = *stack;
	while (current)
	{
		if (current->index == -1 && (min == NULL
				|| *(int *)current->content < *(int *)min->content))
			min = current;
		current = current->next;
	}
	return (min);
}

/*Fill the index of every node of the stack.
Index is the final position of the node when it is sorted.
It doesn't change during all the execution.*/
void	fill_index(t_list **stack)
{
	t_list	*min;
	int		i;

	if (!*stack)
		return ;
	i = 1;
	min = find_min(stack);
	while (min)
	{
		min->index = i++;
		min = find_min(stack);
	}
}
