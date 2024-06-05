/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/05 18:42:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_b(t_list **stacka, t_list ** stackb)
{
	t_list	*elem;
	
	calculate_cost(stacka, stackb);
	elem = choose_min_cost(stacka);
	print_stack(stacka);
	print_stack(stackb);
	move_to_b(stacka, stackb, elem);
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
	/*if(!is_sorted(stacka))
		three_args(stacka);
	sort_stack_a(stacka, &stackb);
	*/
}