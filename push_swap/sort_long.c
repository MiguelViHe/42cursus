/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/10 12:33:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_push_a(t_list **stacka, t_list **stackb)
{
	t_list	*min;
	int		len;
	int		movements;

	len = ft_lstsize(*stacka);
	min = lst_min(stacka);
	if (min->position <= len/2)
	{
		movements = min->position;
		while (movements--)
			do_ra(stacka);
	}
	else
	{
		movements = len - min->position;
		while (movements--)
			do_rra(stacka);
	}
	if (*stackb)
		do_pa(stacka, stackb);
}

static void	sort_stack_a(t_list **stacka, t_list **stackb)
{
	t_list	*last;

	last = ft_lstlast(*stacka);
	while (*stackb && (*stackb)->index != 1)
	{
		//ft_printf("index de primero = %d\n", (*stackb)->index);
		if ((*stackb)->index > last->index)
			do_pa(stacka, stackb);
		else
		{
			last = last->prev;
			do_rra(stacka);
		}
		//print_stack(stacka);
		//print_stack(stackb);
	}
}

static void	sort_stack_b(t_list **stacka, t_list **stackb)
{
	t_list	*elem;
	int		size;
	
	size = ft_lstsize(*stacka);
	while (size > 3)
	{
		calculate_cost(stacka, stackb);
		elem = choose_min_cost(stacka);
		//print_stack(stacka);
		//print_stack(stackb);
		move_to_b(stacka, stackb, elem);
		size--;
	}
}

void	sort_long_stack(t_list **stacka)
{
	t_list	*stackb;

	stackb = NULL;
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		do_pb(stacka, &stackb);
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		do_pb(stacka, &stackb);
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		sort_stack_b(stacka, &stackb);
	if(!is_sorted(stacka))
		three_args(stacka);
	/*ft_printf("RESULTADO en B:\n");
	print_stack(stacka);
	print_stack(&stackb);*/
	sort_stack_a(stacka, &stackb);
	/*ft_printf("RESULTADO en A:\n");
	print_stack(stacka);
	print_stack(&stackb);*/
	final_push_a(stacka, &stackb);
	/*ft_printf("RESULTADO final push:\n");
	print_stack(stacka);
	print_stack(&stackb);*/
}