/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:01:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/28 11:57:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stacka)
{
	int	size;
	
	fill_index(stacka);
	fill_position(stacka);
	size = ft_lstsize(*stacka);
	if (size == 2)
		two_args(stacka);
	else if (size == 3)
		three_args(stacka);
	else
	{
		ft_printf("Más largo\n");
		print_stack(stacka);
	}
	free_stack(stacka);
}
