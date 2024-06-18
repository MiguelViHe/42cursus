/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opposite_movs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 13:12:17 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	oppo_ra_rrb(t_list **stacka, t_list **stackb, int costa, int costb)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(costa);
	abs_b = ft_abs(costb);
	while (abs_a || abs_b)
	{
		if (abs_a > 0)
		{
			do_ra(stacka, 1);
			abs_a--;
		}
		if (abs_b > 0)
		{
			do_rrb(stackb, 1);
			abs_b--;
		}
	}
}

static void	oppo_rra_rb(t_list **stacka, t_list **stackb, int costa, int costb)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(costa);
	abs_b = ft_abs(costb);
	while (abs_a || abs_b)
	{
		if (abs_a > 0)
		{
			do_rra(stacka, 1);
			abs_a--;
		}
		if (abs_b > 0)
		{
			do_rb(stackb, 1);
			abs_b--;
		}
	}
}

void	opposite_movs(t_list **stacka, t_list **stackb, int costa, int costb)
{
	if (costa > costb)
		oppo_ra_rrb(stacka, stackb, costa, costb);
	else if (costa < costb)
		oppo_rra_rb(stacka, stackb, costa, costb);
}
