/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/04 14:07:03 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int cost_to_top(t_list **stack, int pos)
{
	int		len;

	len = ft_lstsize(*stack);
	if (pos <= len/2)
			return (pos);
		else
			return (len - pos);
}

static int	cost_to_pos(t_list	**stack, int ndx)
{
	t_list	*aux;
	int		len;
	t_list	*max;
	t_list	*min;
	
	if (stack == NULL)
		return (-1);
	aux = *stack;
	len = ft_lstsize(aux);
	min = lst_min(stack);
	max = lst_max(stack);
	if (ndx < min->index || ndx > max->index)
		return (cost_to_top(stack, max->position));
	while (aux && ndx < aux->index)
		aux = aux->next;
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
		costa = cost_to_top(stacka, aux->position);
		costb = cost_to_pos(stackb, aux->index);
		if (costa == -1 || costb == -1)
			return (0);
		aux->cost = costa + costb + 1;
		aux = aux->next;
	}
	return (1);
}