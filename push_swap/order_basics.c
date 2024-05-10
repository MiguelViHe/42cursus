/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:35:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/09 19:21:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_args(t_list **stack)
{
	t_list	*current;
	if (!*stack)
		return;
	if (is_order(stack))
		return;
}