/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:24:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/10 20:16:16 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_list **stacka, t_list **stackb, t_list *elem)
{
	int	costa;
	int	costb;

	costa = cost_to_top(stacka, elem->position);
	costb = cost_to_pos(stackb, elem->index);
	if (costa * costb <= 0)
		opposite_movs(stacka, stackb, costa, costb);
	else
		same_mov(stacka, stackb, costa, costb);
	elem->cost = 0;
	do_pb(stacka, stackb);
}
