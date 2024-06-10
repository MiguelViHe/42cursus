/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:57:09 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/10 20:23:13 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Swaps the top 2 elements of a stack. 
	Does nothing if there is only one or no elements. */

static int	swap(t_list **stack)
{
	t_list	*first;

	if (stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	first = (*stack)->next;
	(*stack)->next = first->next;
	if (first->next)
		first->next->prev = *stack;
	first->next = *stack;
	(*stack)->prev = first;
	first->prev = NULL;
	*stack = first;
	first->position = 0;
	first->next->position = 1;
	return (1);
}

/*	Swaps the top 2 elements of the stack a. 
	Print "sa" to the standard output. */

void	do_sa(t_list **stacka)
{
	if (swap(stacka))
		ft_printf("sa\n");
}

/*	Swaps the top 2 elements of the stack b. 
	Print "sb" to the standard output. */

void	do_sb(t_list **stackb)
{
	if (swap(stackb))
		ft_printf("sb\n");
}

/*	Swaps the top 2 elements of the stack A and the stack B. 
	Print "ss" to the standard output. */

void	do_ss(t_list **stacka, t_list **stackb)
{
	if (stacka != NULL && ft_lstsize(*stacka) >= 2
		&& stackb != NULL && ft_lstsize(*stackb) >= 2)
	{
		swap(stacka);
		swap(stackb);
		ft_printf("ss\n");
	}
}
