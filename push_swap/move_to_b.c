/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:24:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/12 13:13:32 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_side(t_list **stacka, t_list **stackb, int costop, int costpos)
{
	int	side;
	int	bad_a;
	int	bad_b;
	int	cost;

	cost = ft_abs(costop) + ft_abs(costpos);
	side = 0;
	bad_a = ft_lstsize(*stacka) - ft_abs(costop);
	bad_b = ft_lstsize(*stackb) - ft_abs(costpos);
	if (cost > ft_biggest(ft_abs(costop), bad_b))
	{
		cost = ft_biggest(ft_abs(costop), bad_b);
		if (costop > 0)
			side = 1;
		else
			side = -1;
	}
	if (cost > ft_biggest(ft_abs(costpos), bad_a))
	{
		cost = ft_biggest(ft_abs(costpos), bad_a);
		if (costpos > 0)
			side = 2;
		else
			side = -2;
	}
	return (side);
}

void	move_to_b(t_list **stka, t_list **stkb, t_list *elem)
{
	int	costa;
	int	costb;
	int side;

	costa = cost_to_top(stka, elem->position);
	costb = cost_to_pos(stkb, elem->index);
	if (costa * costb < 0)
	{
		side = choose_side(stka, stkb, costa, costb);
		if (side == 1)
			same_mov(stka, stkb, costa, ft_lstsize(*stkb) - ft_abs(costb));
		else if (side == -1)
			same_mov(stka, stkb, costa, (ft_lstsize(*stkb) - ft_abs(costb)) * -1);
		else if (side == 2)
			same_mov(stka, stkb, ft_lstsize(*stka) - ft_abs(costa), costb);
		else if (side == -2)
			same_mov(stka, stkb, (ft_lstsize(*stka) - ft_abs(costa)) * -1, costb);
		else if (side == 0)
			opposite_movs(stka, stkb, costa, costb);
	}
	else
		same_mov(stka, stkb, costa, costb);
	elem->cost = 0;
	do_pb(stka, stkb);
}
