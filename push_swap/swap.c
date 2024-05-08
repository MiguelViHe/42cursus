/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:57:09 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/08 11:39:26 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Swaps the top 2 elements of a stack. 
	Does nothing if there is only one or no elements. */

static void	swap(t_list **stack)
{
	t_list	*first; 
	
	if (stack == NULL || ft_lstsize(*stack) < 2)
		return;
	first = (*stack)->next;
	(*stack)->next = ((*stack)->next)->next;
	first->next = *stack;
	*stack = first;
}

/*	Swaps the top 2 elements of the stack a. 
	Print "sa" to the standard output. */

void	do_sa(t_list **stacka)
{
	swap(stacka);
	ft_printf("sa\n");
}

/*	Swaps the top 2 elements of the stack b. 
	Print "sb" to the standard output. */

void	do_sb(t_list **stackb)
{
	swap(stackb);
	ft_printf("sb\n");
}

/*	Swaps the top 2 elements of the stack A and the stack B. 
	Print "ss" to the standard output. */

void	do_ss(t_list **stacka, t_list **stackb)
{
	swap(stacka);
	swap(stackb);
	ft_printf("ss\n");
}