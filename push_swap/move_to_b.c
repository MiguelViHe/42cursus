/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:24:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 17:15:24 by mvidal-h         ###   ########.fr       */
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
		if (costpos > 0)
			side = 2;
		else
			side = -2;
	}
	return (side);
}

void	move_to_b(t_list **stka, t_list **stkb, t_list *elem)
{
	int	csta;
	int	cstb;
	int	side;

	csta = cost_to_top(stka, elem->position);
	cstb = cost_to_pos(stkb, elem->index);
	if (csta * cstb < 0)
	{
		side = choose_side(stka, stkb, csta, cstb);
		if (side == 1)
			same_mov(stka, stkb, csta, ft_lstsize(*stkb) - ft_abs(cstb));
		else if (side == -1)
			same_mov(stka, stkb, csta, (ft_lstsize(*stkb) - ft_abs(cstb)) * -1);
		else if (side == 2)
			same_mov(stka, stkb, ft_lstsize(*stka) - ft_abs(csta), cstb);
		else if (side == -2)
			same_mov(stka, stkb, (ft_lstsize(*stka) - ft_abs(csta)) * -1, cstb);
		else if (side == 0)
			opposite_movs(stka, stkb, csta, cstb);
	}
	else
		same_mov(stka, stkb, csta, cstb);
	elem->cost = 0;
	do_pb(stka, stkb, 1);
}
