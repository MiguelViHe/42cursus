/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:26:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 12:57:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Pushes the top element of stackx to the top of stacky*/

static int	push(t_list **stackx, t_list **stacky)
{
	t_list	*firstx;

	if (stackx == NULL || ft_lstsize(*stackx) < 1)
		return (0);
	firstx = (*stackx)->next;
	(*stackx)->next = *stacky;
	*stacky = *stackx;
	*stackx = firstx;
	if ((*stacky)->next)
		(*stacky)->next->prev = *stacky;
	if (*stackx)
		(*stackx)->prev = NULL;
	return (1);
}

/*	Pushes the top element of stack b to the top of stack a.
	Prints "pa" to the standard output. */

void	do_pa(t_list **stacka, t_list **stackb, int print)
{
	if (push(stackb, stacka))
	{
		update_stacks_positions(stacka, stackb);
		if (print)
			ft_printf("pa\n");
	}
}

/*	Pushes the top element of stack a to the top of stack b.
	Prints "pb" to the standard output. */

void	do_pb(t_list **stacka, t_list **stackb, int print)
{
	if (push(stacka, stackb))
	{
		update_stacks_positions(stacka, stackb);
		if (print)
			ft_printf("pb\n");
	}
}
