/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/06 17:52:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_b(t_list **stacka, t_list ** stackb)
{
	t_list	*elem;
	int		size;
	
	size = ft_lstsize(*stacka);
	while (size > 3)
	{
		calculate_cost(stacka, stackb);
		elem = choose_min_cost(stacka);
		print_stack(stacka);
		print_stack(stackb);
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
	ft_printf("RESULTADO:\n");
	print_stack(stacka);
	print_stack(&stackb);
	/*sort_stack_a(stacka, &stackb);
	*/
}