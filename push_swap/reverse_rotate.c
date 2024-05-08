/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:58:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/08 12:24:20 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void reverse(t_list **stack)
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

/*	Brings the bottom element of the stack a to the top.
	Print "rra" to the standard output.  */

void	do_rra(t_list **stacka)
{
	reverse(stacka);
	ft_printf("rra\n");
}

/*	Brings the bottom element of the stack b to the top.
	Print "rrb" to the standard output.  */

void	do_rrb(t_list **stackb)
{
	reverse(stackb);
	ft_printf("rrb\n");
}

/*	Brings the bottom elements of the stack a and the stack b to the top.
	of their stacks. Print "rrr" to the standard output.  */

void	do_rrr(t_list **stacka, t_list **stackb)
{
	reverse(stacka);
	reverse(stackb);
	ft_printf("rrr\n");
}