/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:11:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/04 00:26:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Find and return de index of the smallest element.

int	lst_min(t_list **stack)
{
	t_list	*aux;
	int		min;

	if (!*stack)
		return (-1);
	aux = *stack;
	min = aux->index;
	aux = aux->next;
	while (aux)
	{
		if (aux->index < min)
			min = aux->index;
		aux = aux->next;
	}
}

//Find and return de index of the biggest element.

int	lst_max(t_list **stack)
{
	t_list	*aux;
	int		max;

	if (!*stack)
		return (-1);
	aux = *stack;
	max = aux->index;
	aux = aux->next;
	while (aux)
	{
		if (aux->index > max)
			max = aux->index;
		aux = aux->next;
	}
}