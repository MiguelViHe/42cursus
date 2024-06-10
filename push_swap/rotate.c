/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:43:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/10 20:24:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sends the top element of the stack to the bottom. */

static int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	first = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = last;
	first->prev = NULL;
	*stack = first;
	return (1);
}

/*	Sends the top element of the stack a to the bottom.
	Print "ra" to the standard output.  */

void	do_ra(t_list **stacka)
{
	if (rotate(stacka))
	{
		fill_position(stacka);
		ft_printf("ra\n");
	}
}

/*	Sends the top element of the stack b to the bottom.
	Print "rb" to the standard output.  */

void	do_rb(t_list **stackb)
{
	if (rotate(stackb))
	{
		fill_position(stackb);
		ft_printf("rb\n");
	}
}

/*	Sends the top elements of the stack a and the stack b to the bottom.
	of their stacks. Print "rr" to the standard output.  */

void	do_rr(t_list **stacka, t_list **stackb)
{
	if (stacka != NULL && ft_lstsize(*stacka) >= 2
		&& stackb != NULL && ft_lstsize(*stackb) >= 2)
	{
		rotate(stacka);
		rotate(stackb);
		update_stacks_positions(stacka, stackb);
		ft_printf("rr\n");
	}
}
