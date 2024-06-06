/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opposite_movs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/06 17:34:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	opposite_ra_rrb(t_list **stacka, t_list **stackb, int costa, int costb)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(costa);
	abs_b = ft_abs(costb);
	while (abs_a || abs_b)
	{
		if (abs_a > 0)
		{
			do_ra(stacka);
			abs_a--;
		}
		if (abs_b > 0)
		{
			do_rrb(stackb);
			abs_b--;
		}
	}
}

static void	opposite_rra_rb(t_list **stacka, t_list **stackb, int costa, int costb)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(costa);
	abs_b = ft_abs(costb);
	while (abs_a || abs_b)
	{
		if (abs_a > 0)
		{
			do_rra(stacka);
			abs_a--;
		}
		if (abs_b > 0)
		{
			do_rb(stackb);
			abs_b--;
		}
	}
}

void	opposite_movs(t_list **stacka, t_list **stackb, int costa, int costb)
{
	if (costa > costb)
		opposite_ra_rrb(stacka, stackb, costa, costb);
	else if (costa < costb)
		opposite_rra_rb(stacka, stackb, costa, costb);
}