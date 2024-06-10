/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:11:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/07 13:28:26 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Find and return the smallest element.

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

//Find and return the biggest element.

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