/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:23:38 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/09 13:19:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Return 1 if the stack is order an 0 if not*/

int	is_order(t_list **stack)
{
	t_list	*current;

	if(!(*stack))
		return (-1);
	current = *stack;
	while(current->next)
	{	
		if(*(int *)current->content < *(int *)current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}