/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:35:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/13 18:14:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_args(t_list **stack)
{
	if (!*stack)
		return;
	if (is_sorted(stack))
		return;
	else
		do_sa(stack);
}

void	three_args(t_list **stack)
{
	if (!*stack)
		return;
	while (!is_sorted(stack))
	{
		if (((*stack)->index < (*stack)->next->index && 
			(*stack)->index < (*stack)->next->next->index) ||
			((*stack)->index < (*stack)->next->index && 
			(*stack)->index > (*stack)->next->next->index))
			do_rra(stack);
		else if ((*stack)->index > (*stack)->next->index && 
				(*stack)->index < (*stack)->next->next->index)
			do_sa(stack);
		else if ((*stack)->index > (*stack)->next->index && 
				(*stack)->index > (*stack)->next->next->index)
			do_ra(stack);
	}
}