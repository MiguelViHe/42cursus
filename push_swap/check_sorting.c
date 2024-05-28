/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:26:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/27 12:56:09 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Return 1 if the stack is order an 0 if not*/

int	is_sorted(t_list **stack)
{
	t_list	*current;

	if (!(*stack))
		return (-1);
	current = *stack;
	while (current->next)
	{
		if (*(int *)current->content < *(int *)current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
