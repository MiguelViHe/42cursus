/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:24:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/05 18:57:17 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_list **stacka, t_list **stackb, t_list *elem)
{
	int	costa;
	int costb;
	
	costa = cost_to_top(stacka, elem->position);
	costb = cost_to_pos(stackb, elem->index);
	ft_printf("index = %d, a%d, b%d\n",elem->index, costa, costb);
	if (costop * costpos < 0)
	else if (costop * costpos = 0)
	else

	/*int	abs_costop;
	int	abs_costpos;
	
	abs_costop = ft_abs(costop);
	abs_costpos = ft_abs(costpos);
	if (costop * costpos <= 0)
		return (abs_costop + abs_costpos);
	else
		if (abs_costop >= abs_costpos)
			return (abs_costpos + (abs_costop - abs_costpos));
		else
			return (abs_costop + (abs_costpos - abs_costop));*/
}