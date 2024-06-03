/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/03 14:00:12 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_list **stack)
{
	t_list *aux;
	int		len;

	aux = *stack;
	len = ft_lstsize(aux);
	while(aux)
	{
		if (aux->position <= len/2)
			aux->cost = aux->position;
		else
			aux->cost = len - aux->position;
		aux = aux->next;
	}
}