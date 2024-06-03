/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:58:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/30 19:40:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static int	reverse(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	last = ft_lstlast(*stack);
	prev = ft_lstprev(*stack, last);
	last->next = *stack;
	prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	return (1);
}

/*	Brings the bottom element of the stack a to the top.
	Print "rra" to the standard output.  */

void	do_rra(t_list **stacka)
{
	if (reverse(stacka))
	{
		fill_position(stacka);
		ft_printf("rra\n");
	}
}

/*	Brings the bottom element of the stack b to the top.
	Print "rrb" to the standard output.  */

void	do_rrb(t_list **stackb)
{
	if (reverse(stackb))
	{
		fill_position(stackb);
		ft_printf("rrb\n");
	}
}

/*	Brings the bottom elements of the stack a and the stack b to the top.
	of their stacks. Print "rrr" to the standard output.  */

void	do_rrr(t_list **stacka, t_list **stackb)
{
	if (stacka != NULL && ft_lstsize(*stacka) >= 2
			&& stackb != NULL && ft_lstsize(*stackb) >= 2)
	{
		reverse(stacka);
		reverse(stackb);
		update_stacks_positions(stacka, stackb);
		ft_printf("rrr\n");
	}
	
	
}
