/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:01:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/03 13:56:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_long_stack(t_list **stacka)
{
	
}*/

void	sort_stack(t_list **stacka)
{
	int	size;
	t_list	*stackb;
	
	fill_index(stacka);
	fill_position(stacka);
	calculate_cost(stacka);
	size = ft_lstsize(*stacka);
	if (size == 2)
		two_args(stacka);
	else if (size == 3)
		three_args(stacka);
	else
	{
		stackb = NULL;
		ft_printf("Más largo\n");
		print_stack(stacka);
		print_stack(&stackb);
		do_pb(stacka, &stackb);
		do_pb(stacka, &stackb);
		do_pb(stacka, &stackb);
		print_stack(stacka);
		print_stack(&stackb);
		do_rr(stacka, &stackb);
		print_stack(stacka);
		print_stack(&stackb);
		do_rrr(stacka, &stackb);
		print_stack(stacka);
		print_stack(&stackb);
		do_ss(stacka, &stackb);
		print_stack(stacka);
		print_stack(&stackb);
	}
	free_stack(stacka);
}
