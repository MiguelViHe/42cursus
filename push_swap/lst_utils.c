/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:11:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/04 14:00:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Find and return de index of the smallest element.

t_list	*lst_min(t_list **stack)
{
	t_list	*aux;
	t_list	*min;

	if (!*stack)
		return (NULL);
	aux = *stack;
	min = aux;
	aux = aux->next;
	while (aux)
	{
		if (aux->index < min->index)
			min = aux;
		aux = aux->next;
	}
	return (min);
}

//Find and return de index of the biggest element.

t_list	*lst_max(t_list **stack)
{
	t_list	*aux;
	t_list	*max;

	if (!*stack)
		return (NULL);
	aux = *stack;
	max = aux;
	aux = aux->next;
	while (aux)
	{
		if (aux->index > max->index)
			max = aux;
		aux = aux->next;
	}
	return (max);
}