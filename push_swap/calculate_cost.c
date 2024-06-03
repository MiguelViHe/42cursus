/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/03 18:51:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int calculate_cost_a(t_list **stack, int pos)
{
	int		len;

	len = ft_lstsize(*stack);
	if (pos <= len/2)
			return (pos);
		else
			return (len - pos);
}

static int	calculate_cost_b(t_list	**stack, int ndx)
{
	t_list	*aux;
	int		len;
	
	if (stack == NULL)
		return (-1);
	aux = *stack;
	len = ft_lstsize(aux);
	while (aux && ndx < aux->index)
		aux = aux->next;
	if (!aux)
		return (0);
	if (aux->position <= len/2)
			return (aux->position);
		else
			return (len - aux->position);
}

int	calculate_cost(t_list **stacka, t_list **stackb)
{
	t_list	*aux;
	int		costa;
	int		costb;

	aux = *stacka;
	//CONTROLAR SI ES EL MENOR o EL MAYOR
	while(aux)
	{
		costa = calculate_cost_a(stacka, aux->position);
		costb = calculate_cost_b(stackb, aux->index);
		if (costa == -1 || costb == -1)
			return (0);
		aux->cost = costa + costb;
		aux = aux->next;
	}
	return (1);
}