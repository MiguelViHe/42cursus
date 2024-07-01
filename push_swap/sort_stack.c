/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:01:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 13:45:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Initialize the index and the position of every node of the list and
check the length of the stack to sort two, three or longer stacks*/
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
		sort_long_stack(stacka);
}
