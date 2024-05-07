/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:31:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/07 20:09:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack)
{
	t_list	*first; 
	
	if (stack == NULL || ft_lstsize(*stack) < 2)
		return;
	first = (*stack)->next;
	(*stack)->next = ((*stack)->next)->next;
	first->next = *stack;
	*stack = first;
}

void push(t_list **stackx, t_list **stacky)
{
	t_list	*firstx;

	if (stackx == NULL || ft_lstsize(*stackx) < 1)
		return;
	firstx = (*stackx)->next;
	(*stackx)->next = *stacky;
	*stacky = *stackx;
	*stackx = firstx;
}

void reverse(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (stack == NULL || ft_lstsize(*stack) < 2)
		return;
	last = ft_lstlast(*stack);
	prev = ft_lstprev(*stack, last);
	last->next = *stack;
	*stack = last;
	prev->next = NULL;
}

void rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (stack == NULL || ft_lstsize(*stack) < 2)
		return;
	first = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = first;
}