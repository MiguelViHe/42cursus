/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:54:58 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 13:48:13 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	same_ra_rb(t_list **stacka, t_list **stackb, int abs_a, int abs_b)
{
	while (abs_a && abs_b)
	{
		do_rr(stacka, stackb, 1);
		abs_a--;
		abs_b--;
	}
	while (abs_a)
	{
		do_ra(stacka, 1);
		abs_a--;
	}
	while (abs_b)
	{
		do_rb(stackb, 1);
		abs_b--;
	}
}

static void	same_rra_rrb(t_list **stacka, t_list **stackb, int abs_a, int abs_b)
{
	while (abs_a && abs_b)
	{
		do_rrr(stacka, stackb, 1);
		abs_a--;
		abs_b--;
	}
	while (abs_a)
	{
		do_rra(stacka, 1);
		abs_a--;
	}
	while (abs_b)
	{
		do_rrb(stackb, 1);
		abs_b--;
	}
}

void	same_mov(t_list **stacka, t_list **stackb, int costa, int costb)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(costa);
	abs_b = ft_abs(costb);
	if (!(costa == 0 && costb == 0))
	{
		if (costa > 0 || costb > 0)
			same_ra_rb(stacka, stackb, abs_a, abs_b);
		else
			same_rra_rrb(stacka, stackb, abs_a, abs_b);
	}
}
